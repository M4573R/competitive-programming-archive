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

    unsigned int exponent;
    cin >> exponent;

    if (exponent == 1)
    {
        cout << 1 << ' ' << 2 << ' ' << 3;
    }
    else if (exponent == 2)
    {
        cout << 3 << ' ' << 4 << ' ' << 5;
    }
    else
    {
        cout << -1;
    }

    cout << '\n';

    return 0;
}
