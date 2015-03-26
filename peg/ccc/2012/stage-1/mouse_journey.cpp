#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int paths_count(unsigned int rows,
                         unsigned int columns,
                         const vector<vector<bool>>& has_cats)
{
    vector<vector<unsigned int>> paths(rows, vector<unsigned int>(columns));

    for (unsigned int i {0}; i < columns && !has_cats[0][i]; ++i)
    {
        paths[0][i] = 1;
    }

    for (unsigned int i {0}; i < rows && !has_cats[i][0]; ++i)
    {
        paths[i][0] = 1;
    }

    for (unsigned int i {1}; i < rows; ++i)
    {
        for (unsigned int j {1}; j < columns; ++j)
        {
            if (!has_cats[i][j])
            {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
    }

    return paths[rows - 1][columns - 1];
}

int main()
{
    use_io_optimizations();

    unsigned int rows;
    unsigned int columns;
    unsigned int cats;

    cin >> rows >> columns >> cats;

    vector<vector<bool>> has_cats(rows, vector<bool>(columns));

    for (unsigned int i {0}; i < cats; ++i)
    {
        unsigned int row;
        unsigned int column;

        cin >> row >> column;

        has_cats[row - 1][column - 1] = true;
    }

    cout << paths_count(rows, columns, has_cats) << '\n';

    return 0;
}
