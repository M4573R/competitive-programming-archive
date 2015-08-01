#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int digits_sum(unsigned int number)
{
    unsigned int sum {0};

    for (unsigned int i {number}; i > 0; i /= 10)
    {
        sum += i % 10;
    }

    return sum;
}

unsigned int factors_digits_sum(unsigned int number)
{
    unsigned int sum {0};

    for (unsigned int i {number}, factor {2}; i > 1; ++factor)
    {
        while (i % factor == 0)
        {
            i /= factor;
            sum += digits_sum(factor);
        }
    }

    return sum;
}

int main()
{
    use_io_optimizations();

    unsigned int number;
    cin >> number;

    cout << (digits_sum(number) == factors_digits_sum(number)) << '\n';

    return 0;
}
