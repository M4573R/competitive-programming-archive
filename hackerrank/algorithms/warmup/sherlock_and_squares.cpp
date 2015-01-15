#include <iostream>

using namespace std;

inline void use_io_optimizations()
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
        unsigned int lower_bound;
        unsigned int upper_bound;

        cin >> lower_bound >> upper_bound;

        unsigned int square_integers {0};

        for (unsigned int i {0}; i * i <= upper_bound; ++i)
        {
            if (i * i >= lower_bound)
            {
                ++square_integers;
            }
        }

        cout << square_integers << '\n';
    }

    return 0;
}
