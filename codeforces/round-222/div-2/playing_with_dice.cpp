#include <cstdlib>
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

    int first;
    int second;

    cin >> first >> second;

    int wins   {0};
    int draws  {0};
    int losses {0};

    for (int die {1}; die <= 6; ++die)
    {
        if (abs(first - die) < abs(second - die))
        {
            ++wins;
        }
        else if (abs(first - die) > abs(second - die))
        {
            ++losses;
        }
        else
        {
            ++draws;
        }
    }

    cout << wins << ' ' << draws << ' ' << losses << '\n';

    return 0;
}
