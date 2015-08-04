#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int exponentiate(unsigned int base,
                          unsigned int exponent,
                          unsigned int modulo)
{
    unsigned long long result    {1};
    unsigned long long aggregate {base};

    for (unsigned int i {exponent}; i > 0; i /= 2)
    {
        if (i % 2)
        {
            result = (result * aggregate) % modulo;
        }

        aggregate = (aggregate * aggregate) % modulo;
    }

    return result;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int bulbs;
        cin >> bulbs;

        cout << (exponentiate(2, bulbs, 100000) + 99999) % 100000 << '\n';
    }

    return 0;
}
