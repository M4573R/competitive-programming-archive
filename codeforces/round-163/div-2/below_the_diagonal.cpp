#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

constexpr unsigned int rows_swap    {1};
constexpr unsigned int columns_swap {2};

void move_left_non_zero_columns(vector<unsigned int>& ones_in_columns,
                                vector<vector<unsigned int>>& moves,
                                unsigned int dimension)
{
    for (unsigned int zero {1}, non_zero {2}; non_zero <= dimension;)
    {
        if (ones_in_columns[zero] != 0)
        {
            ++zero;

            if (zero >= non_zero)
            {
                non_zero = zero + 1;
            }
        }
        else
        {
            if (ones_in_columns[non_zero] == 0)
            {
                ++non_zero;
            }
            else
            {
                moves.push_back({columns_swap, zero, non_zero});
                swap(ones_in_columns[zero], ones_in_columns[non_zero]);
            }
        }
    }
}

void sort_rows_by_rightmost_one(vector<unsigned int>& rightmost_in_rows,
                                vector<vector<unsigned int>>& moves,
                                unsigned int dimension)
{
    for (unsigned int i {dimension}; i > 1; --i)
    {
        unsigned int max_rightmost {i};

        for (unsigned int j {i - 1}; j >= 1; --j)
        {
            if (rightmost_in_rows[max_rightmost] < rightmost_in_rows[j])
            {
                max_rightmost = j;
            }
        }

        if (max_rightmost != i)
        {
            moves.push_back({rows_swap, max_rightmost, i});
            swap(rightmost_in_rows[max_rightmost], rightmost_in_rows[i]);
        }
    }
}

int main()
{
    use_io_optimizations();

    unsigned int dimension;
    cin >> dimension;

    vector<unsigned int> rightmost_in_rows(dimension + 1);
    vector<unsigned int> ones_in_columns(dimension + 1);

    for (unsigned int i {0}; i < dimension - 1; ++i)
    {
        unsigned int row;
        unsigned int column;

        cin >> row >> column;

        rightmost_in_rows[row] = max(rightmost_in_rows[row], column);
        ++ones_in_columns[column];
    }

    vector<vector<unsigned int>> moves;

    move_left_non_zero_columns(ones_in_columns,   moves, dimension);
    sort_rows_by_rightmost_one(rightmost_in_rows, moves, dimension);

    cout << moves.size() << '\n';

    for (const auto& move : moves)
    {
        cout << move[0] << ' '
             << move[1] << ' '
             << move[2] << '\n';
    }

    return 0;
}
