#include <algorithm>
#include <iostream>
#include <numeric>
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

    unsigned int sculptures;
    cin >> sculptures;

    vector<int> degrees(sculptures);

    for (auto& degree : degrees)
    {
        cin >> degree;
    }

    int max_sum {accumulate(degrees.cbegin(), degrees.cend(), 0)};

    for (unsigned int i {3}; i <= sculptures; ++i)
    {
        if (sculptures % i == 0)
        {
            vector<int> sums(sculptures / i);

            for (unsigned int j {0}; j < sculptures; ++j)
            {
                sums[j % (sculptures / i)] += degrees[j];
            }

            max_sum = max(max_sum, *max_element(sums.cbegin(), sums.cend()));
        }
    }

    cout << max_sum << '\n';

    return 0;
}
