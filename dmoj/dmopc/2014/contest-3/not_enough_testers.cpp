#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const unsigned int upper_limit {100000};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<vector<unsigned int>> group_by_factors(unsigned int up_to)
{
    vector<unsigned int> factors(up_to + 1);

    for (unsigned int i {1}; i <= up_to; ++i)
    {
        for (unsigned int j {i}; j <= up_to; j += i)
        {
            ++factors[j];
        }
    }

    vector<vector<unsigned int>> by_factors(up_to + 1);

    for (unsigned int i {1}; i <= up_to; ++i)
    {
        by_factors[factors[i]].push_back(i);
    }

    return by_factors;
}

int main()
{
    use_io_optimizations();

    vector<vector<unsigned int>> by_factors {group_by_factors(upper_limit)};

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int factors;
        unsigned int lower;
        unsigned int upper;

        cin >> factors >> lower >> upper;

        cout << upper_bound(by_factors[factors].cbegin(),
                            by_factors[factors].cend(),
                            upper) -
                lower_bound(by_factors[factors].cbegin(),
                            by_factors[factors].cend(),
                            lower)
             << '\n';
    }

    return 0;
}
