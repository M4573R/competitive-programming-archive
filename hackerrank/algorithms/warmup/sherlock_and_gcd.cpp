#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    if (b == 0)
    {
        return a == 0 ? 1 : a;
    }

    for (unsigned int r {a % b}; r > 0; r = a % b)
    {
        a = b;
        b = r;
    }

    return b;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int numbers;
        cin >> numbers;

        unsigned int divisor;
        cin >> divisor;

        for (unsigned int i {1}; i < numbers; ++i)
        {
            unsigned int number;
            cin >> number;

            divisor = gcd(divisor, number);
        }

        cout << (divisor == 1 ? "YES" : "NO") << '\n';
    }

    return 0;
}
