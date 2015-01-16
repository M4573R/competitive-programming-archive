#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    for (unsigned int queries; cin >> queries && queries != 0; )
    {
        int origin_x;
        int origin_y;

        cin >> origin_x >> origin_y;

        for (unsigned int i {0}; i < queries; ++i)
        {
            int x;
            int y;

            cin >> x >> y;

            if (x == origin_x || y == origin_y)
            {
                cout << "divisa";
            }
            else
            {
                cout << (x < origin_x ?
                            (y > origin_y ? "NO" : "SO") :
                            (y > origin_y ? "NE" : "SE"));
            }

            cout << '\n';
        }
    }

    return 0;
}
