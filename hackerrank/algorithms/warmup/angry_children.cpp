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

    unsigned int packets;
    unsigned int children;

    cin >> packets >> children;

    vector<unsigned int> candies(packets);

    for (auto& candies_in_packet : candies)
    {
        cin >> candies_in_packet;
    }

    sort(candies.begin(), candies.end());

    unsigned int min_unfairness {candies.back() - candies.front()};

    for (unsigned int i {0}; i < packets - children; ++i)
    {
        min_unfairness = min(min_unfairness,
                             candies[i + children - 1] - candies[i]);
    }

    cout << min_unfairness << '\n';

    return 0;
}
