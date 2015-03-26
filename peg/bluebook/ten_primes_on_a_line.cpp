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

    return true;
}

int main()
{
    use_io_optimizations();

    unsigned int count;
    cin >> count;

    for (unsigned int i {2}, found {0}; found < count; ++i)
    {
        if (is_prime(i))
        {
            cout << i << (++found % 10 ? ' ' : '\n');
        }
    }

    return 0;
}
