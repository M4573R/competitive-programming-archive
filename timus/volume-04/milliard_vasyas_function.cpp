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

    unsigned int sum;
    cin >> sum;

    vector<vector<unsigned int>> subtasks(10, vector<unsigned int>(sum + 1));

    subtasks[0][0] = 1;

    for (unsigned int i {1}; i <= 9; ++i)
    {
        for (unsigned int j {0}; j <= sum; ++j)
        {
            for (unsigned int k {0}; k <= min(j, 9u); ++k)
            {
                subtasks[i][j] += subtasks[i - 1][j - k];
            }
        }
    }

    cout << subtasks[9][sum] + (sum == 1) << '\n';

    return 0;
}
