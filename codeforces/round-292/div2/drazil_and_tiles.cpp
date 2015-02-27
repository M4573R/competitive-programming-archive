#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const vector<int> delta_x {0, 1, 0, -1};
const vector<int> delta_y {1, 0, -1, 0};

const vector<string> fillers {"<^>v", ">v<^"};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
unsigned int degree(unsigned int x,
                    unsigned int y,
                    const vector<vector<char>>& grid)
{
    unsigned int degree {0};

    for (unsigned int i {0}; i < 4; ++i)
    {
        if (grid[x + delta_x[i]][y + delta_y[i]] == '.')
        {
            ++degree;
        }
    }

    return degree;
}

int main()
{
    use_io_optimizations();

    unsigned int rows;
    unsigned int columns;

    cin >> rows >> columns;

    vector<vector<char>> grid(rows + 2, vector<char>(columns + 2));

    for (unsigned int i {1}; i <= rows; ++i)
    {
        cin >> grid[i].data() + 1;
    }

    vector<pair<unsigned int, unsigned int>> queue;

    for (unsigned int i {1}; i <= rows; ++i)
    {
        for (unsigned int j {1}; j <= columns; ++j)
        {
            if (grid[i][j] == '.' && degree(i, j, grid) == 1)
            {
                queue.emplace_back(i, j);
            }
        }
    }

    for (unsigned int i {0}; i < queue.size(); ++i)
    {
        unsigned int x {queue[i].first};
        unsigned int y {queue[i].second};

        if (grid[x][y] != '.')
        {
            continue;
        }

        unsigned int neighbour_x;
        unsigned int neighbour_y;
        unsigned int neighbour {4};

        for (unsigned int j {0}; j < 4 && neighbour == 4; ++j)
        {
            neighbour_x = x + delta_x[j];
            neighbour_y = y + delta_y[j];

            if (grid[neighbour_x][neighbour_y] == '.')
            {
                neighbour = j;
            }
        }

        if (neighbour == 4)
        {
            cout << "Not unique\n";
            return 0;
        }

        grid[x][y]                     = fillers[0][neighbour];
        grid[neighbour_x][neighbour_y] = fillers[1][neighbour];

        for (unsigned int j {0}; j < 4; ++j)
        {
            unsigned int adjacent_x {neighbour_x + delta_x[j]};
            unsigned int adjacent_y {neighbour_y + delta_y[j]};

            if (grid[adjacent_x][adjacent_y] == '.' &&
                degree(adjacent_x, adjacent_y, grid) == 1)
            {
                queue.emplace_back(adjacent_x, adjacent_y);
            }
        }
    }

    for (unsigned int i {1}; i <= rows; ++i)
    {
        for (unsigned int j {1}; j <= columns; ++j)
        {
            if (grid[i][j] == '.')
            {
                cout << "Not unique\n";
                return 0;
            }
        }
    }

    for (unsigned int i {1}; i <= rows; ++i)
    {
        cout << grid[i].data() + 1 << '\n';
    }

    return 0;
}
