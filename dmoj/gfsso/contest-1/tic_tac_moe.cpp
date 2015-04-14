#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const vector<vector<pair<unsigned int, unsigned int>>> lines {
    {{0, 0}, {0, 1}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 2}, {2, 2}},
    {{0, 0}, {1, 1}, {2, 2}},
    {{0, 2}, {1, 1}, {2, 0}},
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool check(const vector<string>& grid, char player)
{
    for (const auto& line : lines)
    {
        bool has_won {true};

        for (const auto& square : line)
        {
            if (grid[square.first][square.second] != player)
            {
                has_won = false;
            }
        }

        if (has_won)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    use_io_optimizations();

    vector<string> grid(3);

    for (auto& row : grid)
    {
        cin >> row;
    }

    bool griffy_wins  {check(grid, 'O')};
    bool timothy_wins {check(grid, 'X')};

    if (griffy_wins && timothy_wins)
    {
        cout << "Error, redo";
    }
    else if (griffy_wins)
    {
        cout << "Griffy";
    }
    else if (timothy_wins)
    {
        cout << "Timothy";
    }
    else
    {
        cout << "Tie";
    }

    cout << '\n';

    return 0;
}
