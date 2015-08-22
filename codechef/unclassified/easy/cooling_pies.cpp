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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int t {0}; t < test_cases; ++t)
    {
        unsigned int pies_and_racks;
        cin >> pies_and_racks;

        vector<unsigned int> pies_weights(pies_and_racks);
        vector<unsigned int> racks_limits(pies_and_racks);

        for (unsigned int pie {0}; pie < pies_and_racks; ++pie)
        {
            cin >> pies_weights[pie];
        }

        for (unsigned int rack {0}; rack < pies_and_racks; ++rack)
        {
            cin >> racks_limits[rack];
        }

        sort(pies_weights.begin(), pies_weights.end());
        sort(racks_limits.begin(), racks_limits.end());

        unsigned int pie  = 0;
        unsigned int rack = 0;

        while (rack < pies_and_racks)
        {
            if (pies_weights[pie] <= racks_limits[rack])
            {
                ++pie;
            }

            ++rack;
        }

        cout << pie << '\n';
    }

    return 0;
}
