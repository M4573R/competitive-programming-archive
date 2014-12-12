#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    int size;
    cin >> size;

    int label {1};

    vector<vector<int>> shelves(size, vector<int>(size));

    for (int j {size - 1}; j >= 0; --j)
    {
        for (int i {0}; i <= size - 1 - j; ++i)
        {
            shelves[i][j + i] = label++;
        }
    }

    for (int i {1}; i < size; ++i)
    {
        for (int j {0}; j < size - i; ++j)
        {
            shelves[i + j][j] = label++;
        }
    }

    for (int i {0}; i < size; ++i)
    {
        for (int j {0}; j < size; ++j)
        {
            cout << shelves[i][j];

            if (j < size - 1)
            {
                cout << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
