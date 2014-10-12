#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

constexpr char positive     {'+'};
constexpr char negative     {'-'};
constexpr char unrecognized {'?'};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int factorial(unsigned int n)
{
    unsigned int result {1};

    for (unsigned int i {2}; i <= n; ++i)
    {
        result *= i;
    }

    return result;
}

int main()
{
    use_io_optimizations();

    string sent;
    string received;

    cin >> sent >> received;

    int positive_count     {0};
    int negative_count     {0};
    int unrecognized_count {0};

    for (char symbol : sent)
    {
        switch (symbol)
        {
        case positive:
            ++positive_count;
            break;

        case negative:
            ++negative_count;
            break;
        }
    }

    for (char symbol : received)
    {
        switch (symbol)
        {
        case positive:
            --positive_count;
            break;

        case negative:
            --negative_count;
            break;

        case unrecognized:
            ++unrecognized_count;
            break;
        }
    }
    cout << fixed << setprecision(12);

    if (positive_count < 0 || negative_count < 0)
    {
        cout << 0.0 << '\n';
        return 0;
    }

    unsigned int all_choices = pow(2.0, unrecognized_count);
    unsigned int correct_choices {
        factorial(static_cast<unsigned int>(unrecognized_count)) /
        factorial(static_cast<unsigned int>(positive_count))     /
        factorial(static_cast<unsigned int>(negative_count))
    };

    cout << static_cast<double>(correct_choices) / all_choices << '\n';

    return 0;
}
