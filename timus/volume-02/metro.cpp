#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using Quarter = pair<unsigned int, unsigned int>;

constexpr double straight_path {100};
constexpr double diagonal_path {141.421356237};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

double shotest_path(unsigned int metro_x,
                    unsigned int metro_y,
                    const set<Quarter>& diagonal_quarters)
{
    vector<vector<double>> subtasks(metro_x + 1, vector<double>(metro_y + 1));

    for (unsigned int i {1}; i <= metro_x; ++i)
    {
        subtasks[i][0] = i * straight_path;
    }

    for (unsigned int i {1}; i <= metro_y; ++i)
    {
        subtasks[0][i] = i * straight_path;
    }

    for (unsigned int i {1}; i <= metro_x; ++i)
    {
        for (unsigned int j {1}; j <= metro_y; ++j)
        {
            subtasks[i][j] = numeric_limits<double>::infinity();

            if (diagonal_quarters.count(make_pair(i, j)))
            {
                subtasks[i][j] = diagonal_path + subtasks[i - 1][j - 1];
            }

            subtasks[i][j] = min(subtasks[i][j],
                                 straight_path + subtasks[i - 1][j]);
            subtasks[i][j] = min(subtasks[i][j],
                                 straight_path + subtasks[i][j - 1]);
        }
    }

    return subtasks[metro_x][metro_y];
}

int main()
{
    use_io_optimizations();

    unsigned int metro_x;
    unsigned int metro_y;

    cin >> metro_x >> metro_y;

    unsigned int diagonal_quarters_count;
    cin >> diagonal_quarters_count;

    set<Quarter> diagonal_quarters;

    for (unsigned int i {0}; i < diagonal_quarters_count; ++i)
    {
        Quarter quarter;
        cin >> quarter.first >> quarter.second;

        diagonal_quarters.insert(quarter);
    }

    cout << round(shotest_path(metro_x, metro_y, diagonal_quarters)) << '\n';

    return 0;
}
