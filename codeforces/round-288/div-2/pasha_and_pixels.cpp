#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool has_lost(const vector<vector<bool>>& board,
              unsigned int x,
              unsigned int y)
{
    for (int i {-1}; i <= 1; ++i)
    {
        for (int j {-1}; j <= 1; ++j)
        {
            if (board[x + i    ][y + j    ] &&
                board[x + i    ][y + j + 1] &&
                board[x + i + 1][y + j    ] &&
                board[x + i + 1][y + j + 1])
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
    unsigned int moves;

    cin >> rows >> columns >> moves;

    vector<vector<bool>> board(rows + 2, vector<bool>(columns + 2));

    for (unsigned int i {0}; i < moves; ++i)
    {
        unsigned int x;
        unsigned int y;

        cin >> x >> y;
        board[x][y] = true;

        if (has_lost(board, x, y))
        {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';

    return 0;
}
