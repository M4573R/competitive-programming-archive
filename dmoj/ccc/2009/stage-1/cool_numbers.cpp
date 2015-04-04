#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
unsigned int pow_6(unsigned int number)
{
    return number * number * number * number * number * number;
}

int main()
{
    use_io_optimizations();

    unsigned int lower_bound;
    unsigned int upper_bound;

    cin >> lower_bound >> upper_bound;

    unsigned int cool_numbers {0};

    for (unsigned int i {1}; pow_6(i) <= upper_bound; ++i)
    {
        unsigned int number {pow_6(i)};

        if (lower_bound <= number && number <= upper_bound)
        {
            ++cool_numbers;
        }
    }

    cout << cool_numbers << '\n';

    return 0;
}
