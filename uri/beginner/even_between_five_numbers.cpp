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

    unsigned int even_numbers {0};

    for (unsigned int i {0}; i < 5; ++i)
    {
        int number;
        cin >> number;

        if (number % 2 == 0)
        {
            ++even_numbers;
        }
    }

    cout << even_numbers << " valores pares\n";

    return 0;
}
