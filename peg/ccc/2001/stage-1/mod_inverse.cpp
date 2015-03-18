#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long extended_gcd(long long a, long long b, long long& x, long long& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;

        return a;
    }

    long long next_x;
    long long next_y;

    long long gcd {extended_gcd(b, a % b, next_x, next_y)};

    x = next_y;
    y = next_x - (a / b) * next_y;

    return gcd;
}

int main()
{
    use_io_optimizations();

    unsigned int number;
    unsigned int modulo;

    cin >> number >> modulo;

    long long number_quotient;
    long long modulo_quotient;

    long long gcd {extended_gcd(number,
                                modulo,
                                number_quotient,
                                modulo_quotient)};

    if (gcd == 1)
    {
        cout << (number_quotient % modulo + modulo) % modulo;
    }
    else
    {
        cout << "No such integer exists.";
    }

    cout << '\n';

    return 0;
}
