#include <iomanip>
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

    cout << fixed << setprecision(3);

    unsigned int numbers;
    cin >> numbers;

    unsigned int positive {0};
    unsigned int negative {0};
    unsigned int zeros    {0};

    for (unsigned int i {0}; i < numbers; ++i)
    {
        int number;
        cin >> number;

        if (number > 0)
        {
            ++positive;
        }
        else if (number < 0)
        {
            ++negative;
        }
        else
        {
            ++zeros;
        }
    }

    cout << static_cast<double>(positive) / numbers << '\n'
         << static_cast<double>(negative) / numbers << '\n'
         << static_cast<double>(zeros)    / numbers << '\n';

    return 0;
}
