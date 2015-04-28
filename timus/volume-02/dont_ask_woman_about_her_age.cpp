#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

constexpr unsigned int max_base {36};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string number;
    cin >> number;

    unsigned int min_base   {2};
    unsigned int digits_sum {0};

    for (auto digit : number)
    {
        unsigned int in_decimal = digit - (isalpha(digit) ? 'A' - 10 : '0');

        min_base    = max(min_base, in_decimal + 1);
        digits_sum += in_decimal;
    }

    for (unsigned int i {min_base}; i <= max_base; ++i)
    {
        if (digits_sum % (i - 1) == 0)
        {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "No solution.\n";

    return 0;
}
