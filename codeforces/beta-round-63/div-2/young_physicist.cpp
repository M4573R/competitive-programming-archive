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

    unsigned int forces;
    cin >> forces;

    int x_sum {0};
    int y_sum {0};
    int z_sum {0};

    for (unsigned int i {0}; i < forces; ++i)
    {
        int x;
        int y;
        int z;

        cin >> x >> y >> z;

        x_sum += x;
        y_sum += y;
        z_sum += z;
    }

    cout << (x_sum == 0 && y_sum == 0 && z_sum == 0 ? "YES" : "NO") << '\n';

    return 0;
}
