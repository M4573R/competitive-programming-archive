#include <iostream>

using namespace std;

constexpr unsigned int max_summands {45000};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int number;
    cin >> number;

    for (unsigned int summands {max_summands}; ; --summands)
    {
        unsigned int sum {summands * (summands + 1) / 2};

        if ((number >= sum) && ((number - sum) % summands == 0))
        {
            cout << 1 + (number - sum) / summands << ' ' << summands << '\n';
            break;
        }
    }

    return 0;
}
