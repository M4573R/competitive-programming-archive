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

    unsigned int lower_bound;
    unsigned int upper_bound;

    cin >> lower_bound >> upper_bound;

    unsigned int rsa_numbers {0};

    for (unsigned int number {lower_bound}; number <= upper_bound; ++number)
    {
        unsigned int divisors {0};

        for (unsigned int i {1}; i <= number; ++i)
        {
            if (number % i == 0)
            {
                ++divisors;
            }
        }

        if (divisors == 4)
        {
            ++rsa_numbers;
        }
    }

    cout << "The number of RSA numbers between "
         << lower_bound
         << " and "
         << upper_bound
         << " is "
         << rsa_numbers
         << '\n';

    return 0;
}
