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

void read_matrix(unsigned int& rows,
                 unsigned int& columns,
                 vector<string>& matrix)
{
    cin >> rows >> columns;

    matrix.resize(rows);

    for (auto& row : matrix)
    {
        cin >> row;
    }
}

bool is_matching(const vector<string>& grid,
                 const vector<string>& pattern,
                 unsigned int offset_i,
                 unsigned int offset_j)
{
    for (unsigned int i {0}; i < pattern.size(); ++i)
    {
        for (unsigned int j {0}; j < pattern[0].size(); ++j)
        {
            if (grid[i + offset_i][j + offset_j] != pattern[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int grid_rows;
        unsigned int grid_columns;

        vector<string> grid;

        unsigned int pattern_rows;
        unsigned int pattern_columns;

        vector<string> pattern;

        read_matrix(grid_rows,    grid_columns,    grid);
        read_matrix(pattern_rows, pattern_columns, pattern);

        bool found {false};

        for (unsigned int i {0}; i <= grid_rows - pattern_rows && !found; ++i)
        {
            for (unsigned int j {0}; j <= grid_columns - pattern_columns && !found; ++j)
            {
                if (is_matching(grid, pattern, i, j))
                {
                    found = true;
                }
            }
        }

        cout << (found ? "YES" : "NO") << '\n';
    }

    return 0;
}
