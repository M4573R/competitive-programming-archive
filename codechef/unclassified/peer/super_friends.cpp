#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int modulo {1000000007};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned long long exponentiate(unsigned int base, unsigned int exponent)
{
    unsigned long long result    {1};
    unsigned long long aggregate {base};

    for (auto i = exponent; i > 0; i /= 2)
    {
        if (i % 2 == 1)
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
        unsigned int sweets;
        cin >> sweets;

        if (sweets < 6)
        {
            cout << "FIGHT\n";
            continue;
        }

        unsigned long long ways {1};

        for (unsigned int i {sweets - 5}; i <= sweets - 1; ++i)
        {
            ways = (ways * i) % modulo;
        }

        cout << ways * exponentiate(120, modulo - 2) % modulo << '\n';
    }

    return 0;
}
