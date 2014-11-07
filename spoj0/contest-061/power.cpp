#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long exponentiate(unsigned int base,
                       unsigned int exponent,
                       unsigned int modulo)
{
    if (base == 0)
    {
        return 0;
    }

    long long result    {1};
    long long aggregate {base};

    for (unsigned int i {exponent}; i > 0; i /= 2)
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

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int exponent;
        unsigned int modulo;
        unsigned int remainder;

        cin >> exponent >> modulo >> remainder;

        vector<unsigned int> solutions;

        for (unsigned int x {0}; x < modulo; ++x)
        {
            if (exponentiate(x, exponent, modulo) == remainder)
            {
                solutions.push_back(x);
            }
        }

        if (solutions.empty())
        {
            cout << -1;
        }
        else
        {
            for (auto solution = solutions.cbegin();
                 solution != solutions.cend();
                 ++solution)
            {
                cout << *solution;

                if (solution < solutions.cend() - 1)
                {
                    cout << ' ';
                }
            }
        }

        cout << '\n';
    }

    return 0;
}
