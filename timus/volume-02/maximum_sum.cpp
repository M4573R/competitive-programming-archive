#include <iostream>
#include <limits>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int max_subarray_sum(const vector<int>& array)
{
    int sum     {0};
    int max_sum {numeric_limits<int>::min()};

    for (auto element : array)
    {
        sum     = max(sum + element, element);
        max_sum = max(max_sum, sum);
    }

    return max_sum;
}

int max_submatrix_sum(const vector<vector<int>>& matrix)
{
    auto rows    = matrix.size();
    auto columns = matrix.front().size();

    vector<vector<int>> sums(rows + 1, vector<int>(columns + 1));

    for (unsigned int j {0}; j < columns; ++j)
    {
        for (unsigned int i {0}; i < rows; ++i)
        {
            sums[i + 1][j + 1] = sums[i + 1][j] + matrix[i][j];
        }
    }

    int max_sum {numeric_limits<int>::min()};

    for (unsigned int left {1}; left <= columns; ++left)
    {
        for (unsigned int right {left}; right <= columns; ++right)
        {
            vector<int> array(rows);

            for (unsigned int k {0}; k < rows; ++k)
            {
                array[k] = sums[k + 1][right] - sums[k + 1][left - 1];
            }

            max_sum = max(max_sum, max_subarray_sum(array));
        }
    }

    return max_sum;
}

int main()
{
    use_io_optimizations();

    unsigned int size;
    cin >> size;

    vector<vector<int>> matrix(size, vector<int>(size));

    for (auto& row : matrix)
    {
        for (auto& element : row)
        {
            cin >> element;
        }
    }

    cout << max_submatrix_sum(matrix) << '\n';

    return 0;
}
