#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
char operation(unsigned int a, unsigned int b, unsigned int c)
{
    return a + b == c ? '+':
           a - b == c ? '-':
           a * b == c ? '*':
           a == b * c ? '/':
                        '\0';
}

int main()
{
    use_io_optimizations();

    unsigned int a;
    unsigned int b;
    unsigned int c;

    cin >> a >> b >> c;

    if (operation(a, b, c))
    {
        cout << a << operation(a, b, c) << b << '=' << c;
    }
    else
    {
        cout << a << '=' << b << operation(b, c, a) << c;
    }

    cout << '\n';

    return 0;
}
