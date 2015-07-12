#include <iostream>
#include <vector>

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

    unsigned int size;
    cin >> size;

    vector<vector<unsigned int>> board(size + 2, vector<unsigned int>(size + 2));

    for (unsigned int i {1}; i <= size; ++i)
    {
        for (unsigned int j {1}; j <= size; ++j)
        {
            char cell;
            cin >> cell;

            if (cell == 'o')
            {
                board[i][j] = 1;
            }
        }
    }

    for (unsigned int i {1}; i <= size; ++i)
    {
        for (unsigned int j {1}; j <= size; ++j)
        {
            unsigned int neighbours {board[i - 1][j] + board[i + 1][j] +
                                     board[i][j - 1] + board[i][j + 1]};

            if (neighbours % 2)
            {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}
