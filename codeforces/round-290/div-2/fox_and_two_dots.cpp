#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const vector<pair<int, int>> deltas {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


bool visit(unsigned int x,
           unsigned int y,
           unsigned int from_x,
           unsigned int from_y,
           const vector<vector<char>>& board,
           vector<vector<bool>>& visited)
{
    visited[x][y] = true;

    for (const auto& delta : deltas)
    {
        unsigned int next_x {x + delta.first};
        unsigned int next_y {y + delta.second};

        if (board[x][y] == board[next_x][next_y] &&
            !(next_x == from_x && next_y == from_y))
        {
            if (visited[next_x][next_y] ||
                visit(next_x, next_y, x, y, board, visited))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    use_io_optimizations();

    unsigned int rows;
    unsigned int columns;

    cin >> rows >> columns;

    vector<vector<char>> board(rows + 2, vector<char>(columns + 2));

    for (unsigned int i {1}; i <= rows; ++i)
    {
        cin >> board[i].data() + 1;
    }

    vector<vector<bool>> visited(rows + 2, vector<bool>(columns + 2));

    for (unsigned int i {1}; i <= rows; ++i)
    {
        for (unsigned int j {1}; j <= columns; ++j)
        {
            if (!visited[i][j])
            {
                if (visit(i, j, 0, 0, board, visited))
                {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";

    return 0;
}
