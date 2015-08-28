#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename Input1, typename Input2>
vector<unsigned int> difference(const Input1& left, const Input2& right)
{
    vector<unsigned int> result;

    set_difference(left.cbegin(),  left.cend(),
                   right.cbegin(), right.cend(),
                   back_inserter(result));

    return result;
}

template <typename Input1, typename Input2>
vector<unsigned int> intersection(const Input1& left, const Input2& right)
{
    vector<unsigned int> result;

    set_intersection(left.cbegin(),  left.cend(),
                     right.cbegin(), right.cend(),
                     back_inserter(result));

    return result;
}

void process_weighting(vector<unsigned int>& counterfeit)
{
    unsigned int coins;
    cin >> coins;

    set<unsigned int> weighted;

    for (unsigned int i {0}; i < 2 * coins; ++i)
    {
        unsigned int coin;
        cin >> coin;

        weighted.insert(coin);
    }

    char result;
    cin >> result;

    if (result == '=')
    {
        counterfeit = difference(counterfeit, weighted);
    }
    else
    {
        counterfeit = intersection(counterfeit, weighted);
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int coins;
        unsigned int weightings;

        cin >> coins >> weightings;

        vector<unsigned int> counterfeit(coins);

        for (unsigned int i {0}; i < coins; ++i)
        {
            counterfeit[i] = i + 1;
        }

        for (unsigned int i {0}; i < weightings; ++i)
        {
            process_weighting(counterfeit);
        }

        cout << (counterfeit.size() == 1 ? counterfeit.front() : 0) << '\n';

        if (test + 1 < test_cases)
        {
            cout << '\n';
        }
    }

    return 0;
}
