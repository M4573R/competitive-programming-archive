#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename FirstSet, typename SecondSet>
inline FirstSet unite(const FirstSet& left, const SecondSet& right)
{
    FirstSet united;

    set_union(left.begin(),
              left.end(),
              right.begin(),
              right.end(),
              inserter(united, united.begin()));

    return united;
}

template <typename FirstSet, typename SecondSet>
inline FirstSet intersect(const FirstSet& left, const SecondSet& right)
{
    FirstSet intersection;

    set_intersection(left.begin(),
                     left.end(),
                     right.begin(),
                     right.end(),
                     inserter(intersection, intersection.begin()));

    return intersection;
}

template <typename FirstSet, typename SecondSet>
inline FirstSet subtract(const FirstSet& left, const SecondSet& right)
{
    FirstSet difference;

    set_difference(left.begin(),
                   left.end(),
                   right.begin(),
                   right.end(),
                   inserter(difference, difference.begin()));

    return difference;
}

constexpr unsigned int weighings {3};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        set<char> true_coins;
        set<char> light_coins {'A', 'B', 'C', 'D', 'E', 'F',
                               'G', 'H', 'I', 'J', 'K', 'L'};
        set<char> heavy_coins {'A', 'B', 'C', 'D', 'E', 'F',
                               'G', 'H', 'I', 'J', 'K', 'L'};

        for (unsigned int j {0}; j < weighings; ++j)
        {
            string left;
            string right;
            string weighing;

            cin >> left >> right >> weighing;

            sort(left.begin(), left.end());
            sort(right.begin(), right.end());

            if (weighing == "even")
            {
                true_coins = unite(true_coins, left);
                true_coins = unite(true_coins, right);
            }
            else if (weighing == "up")
            {
                heavy_coins = intersect(heavy_coins, left);
                light_coins = intersect(light_coins, right);
            }
            else if (weighing == "down")
            {
                light_coins = intersect(light_coins, left);
                heavy_coins = intersect(heavy_coins, right);
            }
        }

        light_coins = subtract(light_coins, true_coins);
        heavy_coins = subtract(heavy_coins, true_coins);

        if (!light_coins.empty())
        {
            cout << *light_coins.begin()
                 << " is the counterfeit coin and it is light.\n";
        }
        else if (!heavy_coins.empty())
        {
            cout << *heavy_coins.begin()
                 << " is the counterfeit coin and it is heavy.\n";
        }
    }

    return 0;
}
