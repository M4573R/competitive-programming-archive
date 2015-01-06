#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int knapsack(const vector<unsigned int>& weights,
                      const vector<unsigned int>& values,
                      unsigned int items,
                      unsigned int capacity)
{
    vector<unsigned int> max_values(capacity + 1);

    for (unsigned int i {0}; i < items; ++i)
    {
        for (unsigned int j {capacity}; j >= weights[i]; --j)
        {
            max_values[j] = max(max_values[j],
                                max_values[j - weights[i]] + values[i]);
        }
    }

    return max_values[capacity];
}

int main()
{
    use_io_optimizations();

    unsigned int capacity;
    unsigned int items;

    cin >> capacity >> items;

    vector<unsigned int> weights(items);
    vector<unsigned int> values(items);

    for (unsigned int i {0}; i < items; ++i)
    {
        cin >> weights[i] >> values[i];
    }

    cout << knapsack(weights, values, items, capacity) << '\n';

    return 0;
}
