#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_perfect(unsigned int number)
{
    unsigned int proper_divisors_sum {0};

    for (unsigned int i {1}; i < number; ++i)
    {
        if (number % i == 0)
        {
            proper_divisors_sum += i;
        }
    }

    return proper_divisors_sum == number;
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

        if (is_perfect(number))
        {
            cout << " eh perfeito";
        }
        else
        {
            cout << " nao eh perfeito";
        }

        cout << '\n';
    }

    return 0;
}
