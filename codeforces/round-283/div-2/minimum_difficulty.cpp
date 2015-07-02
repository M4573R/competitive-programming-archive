#include <algorithm>
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

    unsigned int holds;
    cin >> holds;

    vector<unsigned int> heights(holds);

    unsigned int difficulty {0};

    for (unsigned int i {0}; i < holds; ++i)
    {
        cin >> heights[i];

        if (i > 0)
        {
            difficulty = max(difficulty, heights[i] - heights[i - 1]);
        }
    }

    unsigned int min_gap {heights[2] - heights[0]};

    for (unsigned int i {2}; i < holds - 1; ++i)
    {
        min_gap = min(min_gap, heights[i + 1] - heights[i - 1]);
    }

    cout << max(min_gap, difficulty) << '\n';

    return 0;
}
