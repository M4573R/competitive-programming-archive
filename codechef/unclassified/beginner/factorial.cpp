#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int factorial_trailing_zeros(unsigned int number)
{
    unsigned int trailing_zeros {0};

    for (unsigned int i {5}; i <= number; i *= 5)
    {
        trailing_zeros += number / i;
    }

    return trailing_zeros;
}

int main()
{
    use_io_optimizations();

    unsigned int numbers;
    cin >> numbers;

    for (unsigned int i {0}; i < numbers; ++i)
    {
        unsigned int number;
        cin >> number;

        cout << factorial_trailing_zeros(number) << '\n';
    }

    return 0;
}
