#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_prime(unsigned int number)
{
    if (number < 2)
    {
        return false;
    }

    if (number == 2)
    {
        return true;
    }

    if (number % 2 == 0)
    {
        return false;
    }

    for (unsigned int i {3}; i * i <= number; i += 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    use_io_optimizations();

    unsigned int number;
    cin >> number;

    while (!is_prime(number))
    {
        ++number;
    }

    cout << number << '\n';

    return 0;
}
