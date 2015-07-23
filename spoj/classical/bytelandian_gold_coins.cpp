#include <iostream>
#include <map>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

map<unsigned int, unsigned long long> subtasks;

unsigned long long max_profit(unsigned int coin)
{
    if (coin < 12)
    {
        return coin;
    }

    if (subtasks.count(coin))
    {
        return subtasks[coin];
    }

    return subtasks[coin] = (max_profit(coin / 2) +
                             max_profit(coin / 3) +
                             max_profit(coin / 4));
}

int main()
{
    use_io_optimizations();

    for (unsigned int coin; cin >> coin; )
    {
        cout << max_profit(coin) << '\n';
    }

    return 0;
}
