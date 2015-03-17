#include <cctype>
#include <iomanip>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int to_number(const string& name)
{
    unsigned int number {0};

    for (auto symbol : name)
    {
        if (isalpha(symbol))
        {
            number += tolower(symbol) - 'a' + 1;
        }
    }

    return number;
}

unsigned int to_digit(unsigned int number)
{
    while (number > 9)
    {
        unsigned int sum {0};

        while (number > 0)
        {
            sum    += number % 10;
            number /= 10;
        }

        number = sum;
    }

    return number;
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    for (string first, second; getline(cin, first) && getline(cin, second); )
    {
        unsigned int first_sum  {to_digit(to_number(first))};
        unsigned int second_sum {to_digit(to_number(second))};

        double love {
            100.0 * min(first_sum, second_sum) / max(first_sum, second_sum)
        };

        cout << love << " %\n";
    }

    return 0;
}
