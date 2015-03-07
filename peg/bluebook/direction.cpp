#include <iostream>

using namespace std;

inline
void use_io_optimizations()
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
        unsigned int degrees;
        cin >> degrees;

        if (degrees <= 45)
        {
            cout << 'N';
        }
        else if (degrees <= 135)
        {
            cout << 'E';
        }
        else if (degrees <= 225)
        {
            cout << 'S';
        }
        else if (degrees < 315)
        {
            cout << 'W';
        }
        else
        {
            cout << 'N';
        }

        cout << '\n';
    }

    return 0;
}
