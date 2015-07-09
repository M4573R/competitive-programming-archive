#include <iostream>
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

    unsigned int size;
    cin >> size;

    vector<vector<unsigned int>> table(size, vector<unsigned int>(size, 1));

    for (unsigned int i {1}; i < size; ++i)
    {
        for (unsigned int j {1}; j < size; ++j)
        {
            table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
    }

    cout << table[size - 1][size - 1] << '\n';

    return 0;
}
