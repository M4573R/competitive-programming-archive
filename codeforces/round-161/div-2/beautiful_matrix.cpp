#include <cstdlib>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    for (int i {1}; i <= 5; ++i)
    {
        for (int j {1}; j <= 5; ++j)
        {
            bool element;
            cin >> element;

            if (element)
            {
                cout << abs(i - 3) + abs(j - 3) << '\n';
            }
        }
    }

    return 0;
}
