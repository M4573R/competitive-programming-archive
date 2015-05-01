#include <string>
#include <vector>

using namespace std;

constexpr int board_size {8};

class EightRooks
{
public:
    string isCorrect(vector<string> board)
    {
        for (int i {0}; i < board_size; ++i)
        {
            int rooks_in_row    {0};
            int rooks_in_column {0};

            for (int j {0}; j < board_size; ++j)
            {
                rooks_in_row    += (board[i][j] == 'R');
                rooks_in_column += (board[j][i] == 'R');
            }

            if (rooks_in_row != 1 || rooks_in_column != 1)
            {
                return "Incorrect";
            }
        }

        return "Correct";
    }
};
