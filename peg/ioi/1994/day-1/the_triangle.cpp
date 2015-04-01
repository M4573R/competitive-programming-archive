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

int main()
{
    use_io_optimizations();

    unsigned int lines;
    cin >> lines;

    vector<vector<unsigned int>> sums(lines, vector<unsigned int>(lines));

    for (unsigned int i {0}; i < lines; ++i)
    {
        for (unsigned int j {0}; j <= i; ++j)
        {
            unsigned int number;
            cin >> number;

            sums[i][j] += number;

            if (i + 1 < lines)
            {
                sums[i + 1][j]     = max(sums[i + 1][j], sums[i][j]);
                sums[i + 1][j + 1] = max(sums[i + 1][j + 1], sums[i][j]);
            }
        }
    }

    cout << *max_element(sums.back().begin(), sums.back().end()) << '\n';

    return 0;
}
