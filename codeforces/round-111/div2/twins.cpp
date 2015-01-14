#include <algorithm>
#include <functional>
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

    unsigned int coins_count;
    cin >> coins_count;

    unsigned int total {0};
    vector<unsigned int> coins(coins_count);

    for (auto& coin : coins)
    {
        cin >> coin;
        total += coin;
    }

    sort(coins.begin(), coins.end(), greater<unsigned int>());

    unsigned int min_needed_coins {0};

    for (unsigned int i {0}, sum {0}; sum <= total / 2; ++i)
    {
        ++min_needed_coins;
        sum += coins[i];
    }

    cout << min_needed_coins << '\n';

    return 0;
}
