#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr char blank_pixel {'O'};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline void create_table(vector<vector<char>>& table,
                         unsigned int columns,
                         unsigned int rows)
{
    table = vector<vector<char>>(rows + 1,
                                 vector<char>(columns + 1, blank_pixel));
}

void clear_table(vector<vector<char>>& table)
{
    for (unsigned int i {1}; i < table.size(); ++i)
    {
        for (unsigned int j {1}; j < table[0].size(); ++j)
        {
            table[i][j] = blank_pixel;
        }
    }
}

inline void draw_pixel(vector<vector<char>>& table,
                       unsigned int column,
                       unsigned int row,
                       char color)
{
    table[row][column] = color;
}

void draw_vertical_segment(vector<vector<char>>& table,
                           unsigned int column,
                           unsigned int lower_row,
                           unsigned int upper_row,
                           char color)
{
    for (auto row = min(lower_row, upper_row); row <= max(lower_row, upper_row); ++row)
    {
        table[row][column] = color;
    }
}

void draw_horizontal_segment(vector<vector<char>>& table,
                             unsigned int lower_column,
                             unsigned int upper_column,
                             unsigned int row,
                             char color)
{
    for (auto column = min(lower_column, upper_column); column <= max(lower_column, upper_column); ++column)
    {
        table[row][column] = color;
    }
}

void draw_rectangle(vector<vector<char>>& table,
                    unsigned int lower_column,
                    unsigned int lower_row,
                    unsigned int upper_column,
                    unsigned int upper_row,
                    char color)
{
    for (auto row = lower_row; row <= upper_row; ++row)
    {
        for (auto column = lower_column; column <= upper_column; ++ column)
        {
            table[row][column] = color;
        }
    }
}

vector<pair<unsigned int, unsigned int>> adjacent_pixels(unsigned int row,
                                                         unsigned int column,
                                                         unsigned int max_row,
                                                         unsigned int max_column)
{
    vector<pair<unsigned int, unsigned int>> adjacent;

    if (row > 1)
    {
        adjacent.push_back({row - 1, column});
    }

    if (row < max_row)
    {
        adjacent.push_back({row + 1, column});
    }

    if (column > 1)
    {
        adjacent.push_back({row, column - 1});
    }

    if (column < max_column)
    {
        adjacent.push_back({row, column + 1});
    }

    return adjacent;
}

void draw_region2(vector<vector<char>>& table,
                  unsigned int column,
                  unsigned int row,
                  char color,
                  char initial_color)
{
    table[row][column] = color;

    for (pair<unsigned int, unsigned int> pixel : adjacent_pixels(row, column, table.size() - 1, table[0].size() - 1))
    {
        unsigned int x {pixel.first};
        unsigned int y {pixel.second};

        if (table[x][y] == initial_color)
        {
            table[x][y] = color;
            draw_region2(table, y, x, color, initial_color);
        }
    }
}

void draw_region(vector<vector<char>>& table,
                 unsigned int column,
                 unsigned int row,
                 char color)
{
    if (table[row][column] != color)
    {
        draw_region2(table, column, row, color, table[row][column]);
    }
}

void display_picture(vector<vector<char>>& table, string filename)
{
    cout << filename << '\n';

    for (unsigned int i {1}; i < table.size(); ++i)
    {
        for (unsigned int j {1}; j < table[0].size(); ++j)
        {
            cout << table[i][j];
        }

        cout << '\n';
    }
}

int main()
{
    use_io_optimizations();

    vector<vector<char>> table;

    char command;

    while (cin >> command && command != 'X')
    {
        switch (command)
        {
        case 'I':
        {
            unsigned int m, n;
            cin >> m >> n;

            create_table(table, m, n);

            break;
        }

        case 'C':
        {
            clear_table(table);

            break;
        }

        case 'L':
        {
            unsigned int x, y;
            char c;
            cin >> x >> y >> c;

            draw_pixel(table, x, y, c);

            break;
        }

        case 'V':
        {
            unsigned int x, y1, y2;
            char c;
            cin >> x >> y1 >> y2 >> c;

            draw_vertical_segment(table, x, y1, y2, c);

            break;
        }

        case 'H':
        {
            unsigned int x1, x2, y;
            char c;
            cin >> x1 >> x2 >> y >> c;

            draw_horizontal_segment(table, x1, x2, y, c);

            break;
        }

        case 'K':
        {
            unsigned int x1, y1, x2, y2;
            char c;
            cin >> x1 >> y1 >> x2 >> y2 >> c;

            draw_rectangle(table, x1, y1, x2, y2, c);

            break;
        }

        case 'F':
        {
            unsigned int x, y;
            char c;
            cin >> x >> y >> c;

            draw_region(table, x, y, c);

            break;
        }

        case 'S':
        {
            string f;
            cin >> f;

            display_picture(table, f);

            break;
        }
        }
    }

    return 0;
}
