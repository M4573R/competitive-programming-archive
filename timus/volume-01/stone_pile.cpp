#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int min_difference(vector<int>& weights,
                   vector<int>::const_iterator i,
                   int difference)
{
    if (i == weights.cend())
    {
        return difference;
    }

    if (difference == 0)
    {
        return abs(min_difference(weights, i + 1, difference + *i));
    }

    return min(abs(min_difference(weights, i + 1, difference + *i)),
               abs(min_difference(weights, i + 1, difference - *i)));
}

int main()
{
    use_io_optimizations();

    unsigned int stones_count;
    cin >> stones_count;

    vector<int> stones_weights(stones_count);

    for (auto i = stones_weights.begin(); i != stones_weights.end(); ++i)
    {
        cin >> *i;
    }

    cout << min_difference(stones_weights, stones_weights.cbegin(), 0);

    return 0;
}
