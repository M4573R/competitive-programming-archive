#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int factorial(unsigned int number)
{
    unsigned int result {1};

    for (unsigned int i {2}; i <= number; ++i)
    {
        result *= i;
    }

    return result;
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(12);

    string sent;
    string received;

    cin >> sent >> received;

    int positive_count     {0};
    int negative_count     {0};
    int unrecognized_count {0};

    for (auto symbol : sent)
    {
        if (symbol == '+')
        {
            ++positive_count;
        }
        else
        {
            ++negative_count;
        }
    }

    for (auto symbol : received)
    {
        if (symbol == '+')
        {
            --positive_count;
        }
        else if (symbol == '-')
        {
            --negative_count;
        }
        else
        {
            ++unrecognized_count;
        }
    }

    if (positive_count < 0 || negative_count < 0)
    {
        cout << 0.0 << '\n';
    }
    else
    {
        unsigned int all_choices     {1u << unrecognized_count};

        unsigned int correct_choices {factorial(unrecognized_count) /
                                      factorial(positive_count)     /
                                      factorial(negative_count)};

        cout << static_cast<double>(correct_choices) / all_choices << '\n';
    }

    return 0;
}
