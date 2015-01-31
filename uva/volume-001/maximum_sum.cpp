#include <algorithm>
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

int max_subarray(const vector<int>& elements)
{
    int max_sum     {*max_element(elements.cbegin(), elements.cend())};
    int current_sum {0};

    for (auto element : elements)
    {
        current_sum += element;
        max_sum      = max(max_sum, current_sum);

        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }

    return max_sum;
}

int max_submatrix(const vector<vector<int>>& prefix_sums, int size)
{
    int max_sum {numeric_limits<int>::min()};

    for (unsigned int left {1}; left <= size; ++left)
    {
        for (unsigned int right {left}; right <= size; ++right)
        {
            vector<int> row_sums(size);

            for (unsigned int row {1}; row <= size; ++row)
            {
                row_sums[row - 1] = (prefix_sums[row][right] -
                                     prefix_sums[row][left - 1]);
            }

            max_sum = max(max_sum, max_subarray(row_sums));
        }
    }

    return max_sum;
}

int main()
{
    use_io_optimizations();

    unsigned int size;
    cin >> size;

    vector<vector<int>> prefix_sums(size + 1, vector<int>(size + 1));

    for (unsigned int row {1}; row <= size; ++row)
    {
        for (unsigned int column {1}; column <= size; ++column)
        {
            int element;
            cin >> element;

            prefix_sums[row][column] = prefix_sums[row][column - 1] + element;
        }
    }

    cout << max_submatrix(prefix_sums, size) << '\n';

    return 0;
}
