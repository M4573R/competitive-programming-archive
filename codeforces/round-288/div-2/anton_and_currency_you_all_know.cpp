#include <iostream>
#include <string>
#include <utility>

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

    string rate;
    cin >> rate;

    int swap_position {-1};

    for (unsigned int i {0}; i < rate.size() - 1; ++i)
    {
        if ((rate[i] - '0') % 2 == 0)
        {
            swap_position = i;

            if (rate[i] < rate.back())
            {
                break;
            }
        }
    }

    if (swap_position == -1)
    {
        cout << -1 << '\n';
    }
    else
    {
        swap(rate[swap_position], rate.back());
        cout << rate << '\n';
    }

    return 0;
}
