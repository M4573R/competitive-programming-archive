#include <algorithm>
#include <iostream>

using namespace std;

constexpr int leftmost_obstacle  {-1000};
constexpr int rightmost_obstacle { 1000};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int obstacles;
    cin >> obstacles;

    int exit;
    cin >> exit;

    int left_obstacle  {leftmost_obstacle};
    int right_obstacle {rightmost_obstacle};

    for (unsigned int i {0}; i < obstacles; ++i)
    {
        int obstacle;
        cin >> obstacle;

        if (obstacle < 0)
        {
            left_obstacle = max(left_obstacle, obstacle);
        }
        else
        {
            right_obstacle = min(right_obstacle, obstacle);
        }
    }

    if (exit < left_obstacle || exit > right_obstacle)
    {
        cout << "Impossible";
    }
    else if (exit < 0)
    {
        cout << 2 * right_obstacle - exit << ' ' << -exit;
    }
    else
    {
        cout << exit << ' ' << -2 * left_obstacle + exit;
    }

    cout << '\n';

    return 0;
}
