#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int longest_path(const vector<vector<unsigned int>>& triangle)
{
    vector<vector<unsigned int>> subtasks {triangle};

    for (unsigned int i {subtasks.size() - 1}; i > 0; --i)
    {
        for (unsigned int j {0}; j < i; ++j)
        {
            subtasks[i - 1][j] += max(subtasks[i][j], subtasks[i][j + 1]);
        }
    }

    return subtasks[0][0];
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int rows;
        cin >> rows;

        vector<vector<unsigned int>> triangle(rows, vector<unsigned int>(rows));

        for (unsigned int i {0}; i < rows; ++i)
        {
            for (unsigned int j {0}; j <= i; ++j)
            {
                cin >> triangle[i][j];
            }
        }

        cout << longest_path(triangle) << '\n';
    }

    return 0;
}
