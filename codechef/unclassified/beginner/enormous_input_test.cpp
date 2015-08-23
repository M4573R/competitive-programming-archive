#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int numbers;
    unsigned int divisor;

    cin >> numbers >> divisor;

    unsigned int multiples {0};

    for (unsigned int i {0}; i < numbers; ++i)
    {
        unsigned int number;
        cin >> number;

        if (number % divisor == 0)
        {
            ++multiples;
        }
    }

    cout << multiples << '\n';

    return 0;
}
