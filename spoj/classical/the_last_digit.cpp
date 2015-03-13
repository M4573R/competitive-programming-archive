#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int last_digit(unsigned int base, unsigned int exponent)
{
    unsigned int digit        {1};
    unsigned int intermediate {base % 10};

    for (unsigned int i {exponent}; i > 0; i /= 2)
    {
        if (i % 2 == 1)
        {
            digit = (digit * intermediate) % 10;
        }

        intermediate = (intermediate * intermediate) % 10;
    }

    return digit;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int base;
        unsigned int exponent;

        cin >> base >> exponent;

        cout << last_digit(base, exponent) << '\n';
    }

    return 0;
}
