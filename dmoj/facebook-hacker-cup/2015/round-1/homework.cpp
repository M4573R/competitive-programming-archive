#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const unsigned int upper_limit {10000000};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<vector<unsigned int>> group_by_primacity(unsigned int up_to)
{
    vector<unsigned int> primacity(up_to + 1);

    for (unsigned int i {2}; i <= up_to; ++i)
    {
        if (!primacity[i])
        {
            primacity[i] = 1;

            for (unsigned int j {2 * i}; j <= up_to; j += i)
            {
                ++primacity[j];
            }
        }
    }

    vector<vector<unsigned int>> by_primacity(9);

    for (unsigned int i {0}; i <= up_to; ++i)
    {
        by_primacity[primacity[i]].push_back(i);
    }

    return by_primacity;
}

int main()
{
    use_io_optimizations();

    auto by_primacity = group_by_primacity(upper_limit);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int lower;
        unsigned int upper;
        unsigned int primacity;

        cin >> lower >> upper >> primacity;

        cout << "Case #" << test << ": "
             << upper_bound(by_primacity[primacity].cbegin(),
                            by_primacity[primacity].cend(),
                            upper) -
                lower_bound(by_primacity[primacity].cbegin(),
                            by_primacity[primacity].cend(),
                            lower)
            << '\n';
    }

    return 0;
}
