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
    for (unsigned int i {2}; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return number > 1;
}

bool is_palindrome(unsigned int number)
{
    unsigned int reverse {0};

    for (unsigned int i {number}; i > 0; i /= 10)
    {
        reverse = reverse * 10 + i % 10;
    }

    return number == reverse;
}

int main()
{
    use_io_optimizations();

    unsigned int lower_limit;
    cin >> lower_limit;

    unsigned int number {lower_limit};

    while (!is_prime(number) || !is_palindrome(number))
    {
        ++number;
    }

    cout << number << '\n';

    return 0;
}
