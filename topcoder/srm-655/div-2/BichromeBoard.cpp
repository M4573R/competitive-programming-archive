#include <string>
#include <vector>

using namespace std;

class BichromeBoard
{
public:
    string ableToDraw(vector<string> board)
    {
        for (int kind {0}; kind < 2; ++kind)
        {
            bool is_possible {true};

            for (int row {0}; row < board.size(); ++row)
            {
                for (int column {0}; column < board[0].size(); ++column)
                {
                    if (board[row][column] != '?')
                    {
                        if (board[row][column] != expected(kind, row, column))
                        {
                            is_possible = false;
                        }
                    }
                }
            }

            if (is_possible)
            {
                return "Possible";
            }
        }

        return "Impossible";
    }

private:
    char expected(int kind, int row, int column)
    {
        return (kind + row + column) % 2 != 0 ? 'W' : 'B';
    }
};
