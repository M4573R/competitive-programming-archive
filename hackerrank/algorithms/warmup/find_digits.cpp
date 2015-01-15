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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned long long number;
        cin >> number;

        unsigned int digit_divisors {0};

        for (long long i {number}; i > 0; i /= 10)
        {
            unsigned int digit {i % 10};

            if ((digit != 0) && (number % digit == 0))
            {
                ++digit_divisors;
            }
        }

        cout << digit_divisors << '\n';
    }

    return 0;
}
