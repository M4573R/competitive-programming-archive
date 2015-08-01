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
        unsigned int digits;
        cin >> digits;

        unsigned int threes {5 * (2 * digits % 3)};

        if (threes > digits)
        {
            cout << -1;
        }
        else
        {
            unsigned int fives {digits - threes};

            for (unsigned int i {0}; i < fives; ++i)
            {
                cout << 5;
            }

            for (unsigned int i {0}; i < threes; ++i)
            {
                cout << 3;
            }
        }

        cout << '\n';
    }

    return 0;
}
