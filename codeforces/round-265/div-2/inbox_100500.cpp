#include <algorithm>
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

    unsigned int letters;
    cin >> letters;

    unsigned int operations {0};

    for (unsigned int previous {0}, next; cin >> next; previous = next)
    {
        if (next == 1)
        {
            ++operations;

            if (previous == 0)
            {
                ++operations;
            }
        }
    }

    cout << max(1u, operations) - 1 << '\n';

    return 0;
}
