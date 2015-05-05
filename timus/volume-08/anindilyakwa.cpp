#include <cstdlib>
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

int main()
{
    use_io_optimizations();

    long long first;
    long long second;
    long long third;

    cin >> first >> second >> third;

    vector<long long> piles {
        first, second, third
    };

    set<long long> differences {
        abs(first - second), abs(first - third), abs(second - third)
    };

    unsigned int experiments {1};

    while (*differences.begin() != 0)
    {
        ++experiments;

        long long min_difference {*differences.begin()};

        for (auto pile : piles)
        {
            differences.insert(abs(pile - min_difference));
        }

        piles.push_back(min_difference);
    }

    cout << experiments << '\n';

    return 0;
}
