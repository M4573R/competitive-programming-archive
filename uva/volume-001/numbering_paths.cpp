#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int max_intersections {30};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void count_paths(vector<vector<int>>& matrix, unsigned int size)
{
    for (unsigned int k {0}; k <= size; ++k)
    {
        for (unsigned int i {0}; i <= size; ++i)
        {
            for (unsigned int j {0}; j <= size; ++j)
            {
                if (matrix[i][k] && matrix[k][j])
                {
                    matrix[i][j] += matrix[i][k] * matrix[k][j];
                }
            }
        }
    }

    for (unsigned int k {0}; k <= size; ++k)
    {
        if (matrix[k][k])
        {
            for (unsigned int i {0}; i <= size; ++i)
            {
                for (unsigned int j {0}; j <= size; ++j)
                {
                    if (matrix[i][k] && matrix[k][j])
                    {
                        matrix[i][j] = -1;
                    }
                }
            }
        }
    }
}

int main()
{
    use_io_optimizations();

    for (unsigned int city {0}, streets; cin >> streets; ++city)
    {
        vector<vector<int>> matrix(max_intersections,
                                   vector<int>(max_intersections));

        unsigned int intersections {0};

        for (unsigned int i {0}; i < streets; ++i)
        {
            unsigned int source;
            unsigned int destination;

            cin >> source >> destination;

            intersections = max(intersections, source);
            intersections = max(intersections, destination);

            matrix[source][destination] += 1;
        }

        count_paths(matrix, intersections);

        cout << "matrix for city " << city << '\n';

        for (unsigned int i {0}; i <= intersections; ++i)
        {
            for (unsigned int j {0}; j <= intersections; ++j)
            {
                cout << matrix[i][j] << (j == intersections ? '\n' : ' ');
            }
        }
    }

    return 0;
}
