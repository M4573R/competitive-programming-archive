#include <iostream>
#include <utility>
#include <vector>

using namespace std;

constexpr char mine_square {'*'};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline vector<pair<int, int>> adjacent_positions(int row, int column)
{
    return {{row - 1, column    },
            {row + 1, column    },
            {row    , column - 1},
            {row    , column + 1},
            {row - 1, column - 1},
            {row + 1, column + 1},
            {row - 1, column + 1},
            {row + 1, column - 1}};
}

inline bool is_valid_position(int x, int y, int height, int width)
{
    return x >= 0 && x < height && y >= 0 && y < width;
}

void print_field(vector<vector<char>>& field, int field_number)
{
    cout << "Field #" << field_number << ':' << '\n';

    for (vector<char> row : field)
    {
        for (char square : row)
        {
            cout << square;
        }

        cout << '\n';
    }
}

int main()
{
    use_io_optimizations();

    int field_number {1};

    int height;
    int width;

    while (cin >> height >> width && height != 0 && width != 0)
    {
        vector<vector<char>> field(height, vector<char>(width, '0'));

        for (int i {0}; i < height; ++i)
        {
            for (int j {0}; j < width; ++j)
            {
                char square;
                cin >> square;

                if (square == mine_square)
                {
                    field[i][j] = mine_square;

                    for (pair<int, int> position : adjacent_positions(i, j))
                    {
                        int x {position.first};
                        int y {position.second};

                        if (is_valid_position(x, y, height, width) &&
                            field[x][y] != mine_square)
                        {
                            ++field[x][y];
                        }
                    }
                }
            }
        }

        if (field_number > 1)
        {
            cout << '\n';
        }

        print_field(field, field_number++);
    }

    return 0;
}
