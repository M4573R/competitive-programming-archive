#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int max_subarray_sum(const vector<int>& array)
{
    int max_ending_here = 0;
    int max_so_far      = 0;

    for (auto element : array)
    {
        max_ending_here = max(0, max_ending_here + element);
        max_so_far      = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    use_io_optimizations();

    unsigned int bets_count;

    while (cin >> bets_count && bets_count != 0)
    {
        vector<int> bets(bets_count);

        for (unsigned int i {0}; i < bets_count; ++i)
        {
            cin >> bets[i];
        }

        int max_gain {max_subarray_sum(bets)};

        if (max_gain > 0)
        {
            cout << "The maximum winning streak is " << max_gain << ".\n";
        }
        else
        {
            cout << "Losing streak.\n";
        }
    }

    return 0;
}
