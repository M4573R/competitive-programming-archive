#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_lucky(unsigned int number)
{
    for (unsigned int i {number}; i > 0; i /= 10)
    {
        unsigned int digit {i % 10};

        if (digit != 4 && digit != 7)
        {
            return false;
        }
    }

    return number != 0;
}

int main()
{
    use_io_optimizations();

    unsigned int number;
    cin >> number;

    for (unsigned int i {1}; i <= number; ++i)
    {
        if (number % i == 0 && is_lucky(i))
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
