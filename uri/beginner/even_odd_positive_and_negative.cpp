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
    unsigned int odd_numbers  {0};

    unsigned int positive_numbers {0};
    unsigned int negative_numbers {0};

    for (unsigned int i {0}; i < 5; ++i)
    {
        int number;
        cin >> number;

        if (number % 2 == 0)
        {
            ++even_numbers;
        }
        else
        {
            ++odd_numbers;
        }

        if (number > 0)
        {
            ++positive_numbers;
        }
        else if (number < 0)
        {
            ++negative_numbers;
        }
    }

    cout << even_numbers     << " valor(es) par(es)\n"
         << odd_numbers      << " valor(es) impar(es)\n"
         << positive_numbers << " valor(es) positivo(s)\n"
         << negative_numbers << " valor(es) negativo(s)\n";

    return 0;
}
