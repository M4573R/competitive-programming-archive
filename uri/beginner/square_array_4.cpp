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

int main()
{
    use_io_optimizations();

    for (unsigned int size; cin >> size; )
    {
        vector<string> matrix(size, string(size, '0'));

        for (unsigned int i {0}; i < size; ++i)
        {
            matrix[i][i]            = '2';
            matrix[i][size - 1 - i] = '3';
        }

        for (unsigned int i {size / 3}; i < size - size / 3; ++i)
        {
            for (unsigned int j {size / 3}; j < size - size / 3; ++j)
            {
                matrix[i][j] = '1';
            }
        }

        matrix[size / 2][size / 2] = '4';

        for (const auto& row : matrix)
        {
            cout << row << '\n';
        }

        cout << '\n';
    }

    return 0;
}
