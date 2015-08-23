#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned long long exponentiate(unsigned int base,
                                unsigned int exponent,
                                unsigned int modulo)
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
        unsigned int students;
        cin >> students;

        cout << exponentiate(7, students, 1000000007) << '\n';
    }

    return 0;
}
