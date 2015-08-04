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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int number;
        cin >> number;

        unsigned int even_divisors {0};

        for (unsigned int i {1}; i * i <= number; ++i)
        {
            if (number % i == 0)
            {
                if (i % 2 == 0)
                {
                    ++even_divisors;
                }

                unsigned int j {number / i};

                if (j % 2 == 0 && i != j)
                {
                    ++even_divisors;
                }
            }
        }

        cout << even_divisors << '\n';
    }

    return 0;
}
