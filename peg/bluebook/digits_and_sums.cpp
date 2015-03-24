#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int cubed_digits_sum(unsigned int number)
{
    unsigned int sum {0};

    for (unsigned int i {number}; i > 0; i /= 10)
    {
        unsigned int digit {i % 10};

        sum += digit * digit * digit;
    }

    return sum;
}

int main()
{
    use_io_optimizations();

    unsigned int lower_bound;
    unsigned int upper_bound;

    cin >> lower_bound >> upper_bound;

    for (unsigned int i {lower_bound}; i <= upper_bound; ++i)
    {
        if (cubed_digits_sum(i) == i)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
