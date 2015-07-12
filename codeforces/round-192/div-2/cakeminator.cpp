#include <iostream>
#include <set>

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

    unsigned int rows;
    unsigned int columns;

    cin >> rows >> columns;

    set<unsigned int> evil_rows;
    set<unsigned int> evil_columns;

    for (unsigned int i {0}; i < rows; ++i)
    {
        for (unsigned int j {0}; j < columns; ++j)
        {
            char cell;
            cin >> cell;

            if (cell == 'S')
            {
                evil_rows.insert(i);
                evil_columns.insert(j);
            }
        }
    }

    cout << rows * columns - evil_rows.size() * evil_columns.size() << '\n';

    return 0;
}
