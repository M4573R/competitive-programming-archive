#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int valid_numbers(unsigned int digits,
                  unsigned int base,
                  bool could_end_in_zero)
{
    if (digits == 1)
    {
        return base - 1;
    }

    if (could_end_in_zero)
    {
        return (valid_numbers(digits - 1, base, false) +
                (base - 1) * valid_numbers(digits - 1, base, true));
    }
    else
    {
        return (base - 1) * valid_numbers(digits - 1, base, true);
    }
}

int valid_numbers(unsigned int digits, unsigned int base)
{
    if (digits == 0)
    {
        return 0;
    }

    return valid_numbers(digits, base, true);
}

int main()
{
    use_io_optimizations();

    unsigned int digits;
    unsigned int base;

    cin >> digits >> base;

    cout << valid_numbers(digits, base);

    return 0;
}
