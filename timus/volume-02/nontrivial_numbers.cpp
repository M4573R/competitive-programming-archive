#include <iostream>
#include <limits>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int proper_divisors_sum(unsigned int number)
{
    unsigned int sum {1};

    for (unsigned int i {2}; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            sum += i;

            if (i * i != number)
            {
                sum += number / i;
            }
        }
    }

    return sum;
}

unsigned int least_trivial(unsigned int lower, unsigned int upper)
{
    if (lower == 1)
    {
        return 1;
    }

    double min_triviality      {numeric_limits<double>::infinity()};
    unsigned int least_trivial {0};

    for (unsigned int i {upper}; i >= lower; --i)
    {
        unsigned int sum {proper_divisors_sum(i)};

        if (sum == 1)
        {
            least_trivial = i;
            break;
        }

        double triviality {static_cast<double>(sum) / i};

        if (triviality < min_triviality)
        {
            min_triviality = triviality;
            least_trivial  = i;
        }
    }

    return least_trivial;
}

int main()
{
    use_io_optimizations();

    unsigned int lower;
    unsigned int upper;

    cin >> lower >> upper;

    cout << least_trivial(lower, upper) << '\n';

    return 0;
}
