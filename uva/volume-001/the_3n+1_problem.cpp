#include <algorithm>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int cycle_length(unsigned int n)
{
    unsigned int length {1};

    for (unsigned int i {n}; i != 1; ++length)
    {
        if (i % 2 == 0)
        {
            i /= 2;
        }
        else
        {
            i = 3 * i + 1;
        }
    }

    return length;
}

int main()
{
    use_io_optimizations();

    unsigned int first;
    unsigned int second;

    while (cin >> first >> second)
    {
        unsigned int lower_limit {min(first, second)};
        unsigned int upper_limit {max(first, second)};

        unsigned int max_cycle_length {0};

        for (unsigned int i {lower_limit}; i <= upper_limit; ++i)
        {
            max_cycle_length = max(max_cycle_length, cycle_length(i));
        }

        cout << first            << ' '
             << second           << ' '
             << max_cycle_length << '\n';
    }

    return 0;
}
