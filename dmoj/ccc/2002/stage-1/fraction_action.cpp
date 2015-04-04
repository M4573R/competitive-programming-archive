#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    if (b == 0)
    {
        if (a == 0)
        {
            return 1;
        }

        return a;
    }

    for (unsigned int r; r = a % b; )
    {
        a = b;
        b = r;
    }

    return b;
}

int main()
{
    use_io_optimizations();

    unsigned int numerator;
    unsigned int denominator;

    cin >> numerator >> denominator;

    unsigned int divisior {gcd(numerator, denominator)};

    numerator   /= divisior;
    denominator /= divisior;

    if (numerator == 0)
    {
        cout << 0;
    }
    else if (numerator < denominator)
    {
        cout << numerator << '/' << denominator;
    }
    else
    {
        cout << numerator / denominator;
        numerator %= denominator;

        if (numerator != 0)
        {
            cout << ' ' << numerator << '/' << denominator;
        }
    }

    cout << '\n';

    return 0;
}
