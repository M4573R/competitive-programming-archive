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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int pies;
        cin >> pies;

        vector<unsigned int> weights(pies);

        for (auto& weight : weights)
        {
            cin >> weight;
        }

        vector<unsigned int> limits(pies);

        for (auto& limit : limits)
        {
            cin >> limit;
        }

        sort(weights.begin(), weights.end());
        sort(limits.begin(), limits.end());

        unsigned int placed {0};

        for (auto limit : limits)
        {
            if (weights[placed] <= limit)
            {
                ++placed;
            }
        }

        cout << placed << '\n';
    }

    return 0;
}
