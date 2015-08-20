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

    int a;
    int b;
    int c;

    cin >> a >> b >> c;

    if (a == b + c)
    {
        cout << a << '=' << b << '+' << c << '\n';
    }
    else if (a == b - c)
    {
        cout << a << '=' << b << '-' << c << '\n';
    }
    else if (a == b * c)
    {
        cout << a << '=' << b << '*' << c << '\n';
    }
    else if (a * c == b)
    {
        cout << a << '=' << b << '/' << c << '\n';
    }
    else if (a + b == c)
    {
        cout << a << '+' << b << '=' << c << '\n';
    }
    else if (a - b == c)
    {
        cout << a << '-' << b << '=' << c << '\n';
    }
    else if (a * b == c)
    {
        cout << a << '*' << b << '=' << c << '\n';
    }

    return 0;
}
