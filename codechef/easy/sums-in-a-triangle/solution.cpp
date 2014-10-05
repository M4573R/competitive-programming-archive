#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int longest_path(vector<vector<unsigned int>>& triangle)
{
    if (triangle.empty())
    {
        return 0;
    }

    for (vector<unsigned int>::size_type i {triangle.size() - 1}; i > 0; --i)
    {
        for (vector<unsigned int>::size_type j {0}; j < i; ++j)
        {
            triangle[i - 1][j] += max(triangle[i][j], triangle[i][j + 1]);
        }
    }

    return triangle[0][0];
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int t {0}; t < test_cases; ++t)
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
