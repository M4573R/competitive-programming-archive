#include <iostream>
#include <utility>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Chessboard
{
public:
    static constexpr unsigned int noone {0};
    static constexpr unsigned int white {1};
    static constexpr unsigned int black {2};

    Chessboard():
        board(board_size, vector<char>(board_size))
    {
        for (unsigned int i {0}; i < padding; ++i)
        {
            for (unsigned int j {0}; j < board_size; ++j)
            {
                board[i][j] = padding_position;
                board[j][i] = padding_position;

                board[board_size - 1 - i][j] = padding_position;
                board[j][board_size - 1 - i] = padding_position;
            }
        }
    }

    int winner()
    {
        for (auto i = min_row; i < max_row; ++i)
        {
            for (auto j = min_column; j < max_column; ++j)
            {
                if (board[i][j] == WhiteKing && could_be_taken(i, j, black))
                {
                    return black;
                }

                if (board[i][j] == BlackKing && could_be_taken(i, j, white))
                {
                    return white;
                }
            }
        }

        return noone;
    }

    bool empty()
    {
        for (auto i = min_row; i < max_row; ++i)
        {
            for (auto j = min_column; j < max_column; ++j)
            {
                if (board[i][j] != empty_position)
                {
                    return false;
                }
            }
        }

        return true;
    }

    friend istream& operator>>(istream&, Chessboard&);
    friend ostream& operator<<(ostream&, const Chessboard&);

private:
    static constexpr unsigned int board_size {12};
    static constexpr unsigned int padding    {2};

    static constexpr unsigned int min_row {padding};
    static constexpr unsigned int max_row {board_size - padding};

    static constexpr unsigned int min_column {padding};
    static constexpr unsigned int max_column {board_size - padding};

    static constexpr char empty_position   {'.'};
    static constexpr char padding_position {'*'};

    enum Figure
    {
        BlackPawn   = 'p',
        WhitePawn   = 'P',

        BlackKnight = 'n',
        WhiteKnight = 'N',

        BlackBishop = 'b',
        WhiteBishop = 'B',

        BlackRook   = 'r',
        WhiteRook   = 'R',

        BlackQueen  = 'q',
        WhiteQueen  = 'Q',

        BlackKing   = 'k',
        WhiteKing   = 'K'
    };

    vector<vector<char>> board;

    bool could_be_taken(unsigned int x, unsigned int y, unsigned int color)
    {
        vector<Figure> taken_by;

        switch (color)
        {
        case white:
            taken_by = {WhitePawn, WhiteKnight, WhiteBishop,
                        WhiteRook, WhiteQueen,  WhiteKing};
            break;

        case black:
            taken_by = {BlackPawn, BlackKnight, BlackBishop,
                        BlackRook, BlackQueen,  BlackKing};
            break;
        }

        if (taken_by_pawn  (x, y, taken_by[0]) ||
            taken_by_knight(x, y, taken_by[1]) ||
            taken_by_bishop(x, y, taken_by[2]) ||
            taken_by_rook  (x, y, taken_by[3]) ||
            taken_by_queen (x, y, taken_by[4]) ||
            taken_by_king  (x, y, taken_by[5]))
        {
            return true;
        }

        return false;
    }

    bool taken_by_pawn(unsigned int x, unsigned int y, Figure pawn)
    {
        vector<pair<unsigned int, unsigned int>> positions;

        switch (pawn)
        {
        case WhitePawn:
            positions = {{x + 1, y - 1}, {x + 1, y + 1}};
            break;

        case BlackPawn:
            positions = {{x - 1, y - 1}, {x - 1, y + 1}};
            break;
        }

        for (const auto& position : positions)
        {
            if (board[position.first][position.second] == pawn)
            {
                return true;
            }
        }

        return false;
    }

    bool taken_by_knight(unsigned int x, unsigned int y, Figure knight)
    {
        vector<pair<unsigned int, unsigned int>> positions {
            {x - 1, y - 2}, {x - 1, y + 2}, {x - 2, y - 1}, {x - 2, y + 1},
            {x + 1, y - 2}, {x + 1, y + 2}, {x + 2, y - 1}, {x + 2, y + 1}
        };

        for (const auto& position : positions)
        {
            if (board[position.first][position.second] == knight)
            {
                return true;
            }
        }

        return false;
    }

    bool taken_by_bishop(unsigned int x, unsigned int y, Figure bishop)
    {
        vector<pair<int, int>> directions {
            {-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}
        };

        for (const auto& direction : directions)
        {
            unsigned int i {x + direction.first};
            unsigned int j {y + direction.second};

            while (board[i][j] == empty_position)
            {
                i += direction.first;
                j += direction.second;
            }

            if (board[i][j] == bishop)
            {
                return true;
            }
        }

        return false;
    }

    bool taken_by_rook(unsigned int x, unsigned int y, Figure rook)
    {
        vector<pair<int, int>> directions {
            {-1, 0}, {+1, 0}, {0, -1}, {0, +1}
        };

        for (const auto& direction: directions)
        {
            unsigned int i {x + direction.first};
            unsigned int j {y + direction.second};

            while (board[i][j] == empty_position)
            {
                i += direction.first;
                j += direction.second;
            }

            if (board[i][j] == rook)
            {
                return true;
            }
        }

        return false;
    }

    bool taken_by_queen(unsigned int x, unsigned int y, Figure queen)
    {
        return taken_by_bishop(x, y, queen) || taken_by_rook(x, y, queen);
    }

    bool taken_by_king(unsigned int x, unsigned int y, Figure king)
    {
        vector<pair<unsigned int, unsigned int>> positions {
            {x - 1, y - 1}, {x - 1, y}, {x - 1, y + 1},
            {x + 1, y - 1}, {x + 1, y}, {x + 1, y + 1},
            {x, y - 1}, {x, y + 1},
        };

        for (const auto& position : positions)
        {
            if (board[position.first][position.second] == king)
            {
                return true;
            }
        }

        return false;
    }
};

istream& operator>>(istream& input_stream, Chessboard& chessboard)
{
    for (auto i = Chessboard::min_row; i < Chessboard::max_row; ++i)
    {
        for (auto j = Chessboard::min_column; j < Chessboard::max_column; ++j)
        {
            input_stream >> chessboard.board[i][j];
        }
    }

    return input_stream;
}

ostream& operator<<(ostream& output_stream, const Chessboard& chessboard)
{
    for (auto i = Chessboard::min_row; i < Chessboard::max_row; ++i)
    {
        for (auto j = Chessboard::min_column; j < Chessboard::max_column; ++j)
        {
            output_stream << chessboard.board[i][j];
        }

        output_stream << '\n';
    }

    return output_stream;
}

int main()
{
    use_io_optimizations();

    Chessboard chessboard;

    for (unsigned int i {1}; cin >> chessboard && !chessboard.empty(); ++i)
    {
        cout << "Game #" << i << ": ";

        switch (chessboard.winner())
        {
        case Chessboard::noone:
            cout << "no";
            break;

        case Chessboard::white:
            cout << "black";
            break;

        case Chessboard::black:
            cout << "white";
            break;
        }

        cout << " king is in check.\n";
    }

    return 0;
}
