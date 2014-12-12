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

    unsigned int size;
    cin >> size;

    vector<vector<unsigned int>> image(size, vector<unsigned int>(size));

    for (auto& row : image)
    {
        for (auto& pixel : row)
        {
            cin >> pixel;
        }
    }

    for (unsigned int i {0}; i < size; ++i)
    {
        for (unsigned int j {0}; j <= i; ++j)
        {
            cout << image[i - j][j] << ' ';
        }
    }

    for (unsigned int j {1}; j < size; ++j)
    {
        for (unsigned int i {size - 1}; i >= j; --i)
        {
            cout << image[i][j + size - 1 - i];

            if (j < size - 1 || i > j)
            {
                 cout << ' ';
            }
        }
    }

    cout << '\n';

    return 0;
}
