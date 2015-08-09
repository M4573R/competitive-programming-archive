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

unsigned int
exponentiate(unsigned int base, unsigned int exponent, unsigned int modulo)
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

vector<unsigned int>
precalculate_factorials(unsigned int limit, unsigned int modulo)
{
    vector<unsigned int> factorials(limit + 1);

    factorials[0] = 1;

    for (unsigned long long i {1}; i <= limit; ++i)
    {
        factorials[i] = (factorials[i - 1] * i) % modulo;
    }

    return factorials;
}

vector<unsigned int>
precalculate_inverses(const vector<unsigned int>& factorials,
                      unsigned int modulo)
{
    vector<unsigned int> inverses(factorials.size());

    for (vector<unsigned int>::size_type i {0}; i < factorials.size(); ++i)
    {
        inverses[i] = exponentiate(factorials[i], modulo - 2, modulo);
    }

    return inverses;
}

int main()
{
    use_io_optimizations();

    auto factorials = precalculate_factorials(2000000, modulo);
    auto inverses   = precalculate_inverses(factorials, modulo);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int rows;
        unsigned int columns;

        cin >> rows >> columns;

        unsigned long long ways {factorials[rows + columns - 2]};

        ways = (ways * inverses[rows - 1])    % modulo;
        ways = (ways * inverses[columns - 1]) % modulo;

        cout << ways << '\n';
    }

    return 0;
}
