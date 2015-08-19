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

int main()
{
    use_io_optimizations();

    for (unsigned int number; cin >> number && number != 0; )
{
        unsigned int sum        {digits_sum(number)};
        unsigned int multiplier {11};

        while (sum != digits_sum(number * multiplier))
        {
            ++multiplier;
        }

        cout << multiplier << '\n';
    }

    return 0;
}
