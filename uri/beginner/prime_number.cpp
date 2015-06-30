#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_prime(unsigned int number)
{
    if (number == 1)
    {
        return false;
    }

    for (unsigned int i {2}; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
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

        cout << number;

        if (is_prime(number))
        {
            cout << " eh primo";
        }
        else
        {
            cout << " nao eh primo";
        }

        cout << '\n';
    }

    return 0;
}
