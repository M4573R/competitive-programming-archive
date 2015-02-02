#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int min_removed_columns(const vector<string>& table,
                                 unsigned int rows,
                                 unsigned int columns)
{
    unsigned int removed_columns {0};
    vector<bool> are_ordered(columns - 1, false);

    for (unsigned int j {0}; j < columns; ++j)
    {
        bool ok_column {true};

        for (vector<string>::size_type i {0}; i < rows - 1 && ok_column; ++i)
        {
            if (!are_ordered[i] && table[i][j] > table[i + 1][j])
            {
                ok_column = false;
            }
        }

        if (ok_column)
        {
            for (unsigned int i {0}; i < rows - 1; ++i)
            {
                if (table[i][j] < table[i + 1][j])
                {
                    are_ordered[i] = true;
                }
            }
        }
        else
        {
            ++removed_columns;
        }
    }

    return removed_columns;
}

int main()
{
    use_io_optimizations();

    unsigned int rows;
    unsigned int columns;

    cin >> rows >> columns;

    vector<string> table(rows, string(columns, ' '));

    for (auto& row : table)
    {
        cin >> row;
    }

    cout << min_removed_columns(table, rows, columns) << '\n';

    return 0;
}
