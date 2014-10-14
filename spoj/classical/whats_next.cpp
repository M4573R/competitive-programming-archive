#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    int a, b, c;

    while (cin >> a >> b >> c && !(a == 0 && b == 0 && c == 0))
    {
        if (b - a == c - b)
        {
            cout << "AP " << c + b - a << '\n';
        }
        else
        {
            cout << "GP " << c * b / a << '\n';
        }
    }

    return 0;
}
