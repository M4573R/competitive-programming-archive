#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int exponentiate(unsigned int base,
                          unsigned int exponent,
                          unsigned int modulus)
{
    unsigned int result    {1};
    unsigned int aggregate {base};

    for (unsigned int i {exponent}; i > 0; i /= 2)
    {
        if (i % 2 == 1)
        {
            result = (result * aggregate) % modulus;
        }

        aggregate = (aggregate * aggregate) % modulus;
    }

    return result;
}

int main()
{
    use_io_optimizations();

    unsigned int exponent;
    unsigned int modulus;
    unsigned int result;

    cin >> exponent >> modulus >> result;

    bool none_found {true};

    for (unsigned int i {0}; i < modulus; ++i)
    {
        if (exponentiate(i, exponent, modulus) == result)
        {
            if (none_found)
            {
                none_found = false;
            }
            else
            {
                cout << ' ';
            }

            cout << i;
        }
    }

    if (none_found)
    {
        cout << -1;
    }

    cout << '\n';

    return 0;
}
