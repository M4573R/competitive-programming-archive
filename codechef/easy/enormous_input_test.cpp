#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int number_of_entries;
    unsigned int divisor;

    cin >> number_of_entries >> divisor;

    unsigned int divisible_entries {0};

    for (unsigned int i {0}; i < number_of_entries; ++i)
    {
        unsigned int entry;
        cin >> entry;

        if (entry % divisor == 0)
        {
            ++divisible_entries;
        }
    }

    cout << divisible_entries << '\n';

    return 0;
}
