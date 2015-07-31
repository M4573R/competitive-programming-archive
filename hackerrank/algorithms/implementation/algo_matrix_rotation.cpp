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

vector<unsigned int> get_ring(const vector<vector<unsigned int>>& matrix,
                              unsigned int ring_number)
{
    vector<unsigned int> ring;

    int left  = ring_number;
    int right = matrix[0].size() - 1 - ring_number;
    int upper = ring_number;
    int lower = matrix.size() - 1 - ring_number;

    for (int i = left; i <= right; ++i)
    {
        ring.push_back(matrix[upper][i]);
    }

    for (int i = upper + 1; i <= lower; ++i)
    {
        ring.push_back(matrix[i][right]);
    }

    for (int i = right - 1; i >= left; --i)
    {
        ring.push_back(matrix[lower][i]);
    }

    for (int i = lower - 1; i > upper; --i)
    {
        ring.push_back(matrix[i][left]);
    }

    return ring;
}

void set_ring(vector<vector<unsigned int>>& matrix,
              unsigned int ring_number,
              const vector<unsigned int>& ring)
{
    int left  = ring_number;
    int right = matrix[0].size() - 1 - ring_number;
    int upper = ring_number;
    int lower = matrix.size() - 1 - ring_number;

    auto ring_element = ring.cbegin();

    for (int i = left; i <= right; ++i)
    {
        matrix[upper][i] = *ring_element++;
    }

    for (int i = upper + 1; i <= lower; ++i)
    {
        matrix[i][right] = *ring_element++;
    }

    for (int i = right - 1; i >= left; --i)
    {
        matrix[lower][i] = *ring_element++;
    }

    for (int i = lower - 1; i > upper; --i)
    {
        matrix[i][left] = *ring_element++;
    }
}

int main()
{
    use_io_optimizations();

    unsigned int rows;
    unsigned int columns;
    unsigned int rotations;

    cin >> rows >> columns >> rotations;

    vector<vector<unsigned int>> matrix(rows, vector<unsigned int>(columns));

    for (auto& row : matrix)
    {
        for (auto& element : row)
        {
            cin >> element;
        }
    }

    unsigned int rings {(min(rows, columns) + 1) / 2};

    for (unsigned int i {0}; i < rings; ++i)
    {
        auto ring = get_ring(matrix, i);

        rotate(ring.begin(),
               ring.begin() + rotations % ring.size(),
               ring.end());

        set_ring(matrix, i, ring);
    }

    for (unsigned int i {0}; i < rows; ++i)
    {
        for (unsigned int j {0}; j < columns; ++j)
        {
            cout << matrix[i][j] << " \n"[j + 1 == columns];
        }
    }

    return 0;
}
