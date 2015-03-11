#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

unsigned int min_difference(const vector<unsigned int>& weights,
                            unsigned int total)
{
    vector<bool> possible(total / 2 + 1);
    possible[0] = true;

    unsigned int closest = 0;

    for (unsigned int i = 0; i < weights.size(); ++i)
    {
        for (unsigned int weight = total / 2; weight >= weights[i]; --weight)
        {
            if (possible[weight - weights[i]])
            {
                possible[weight] = true;
                closest = max(closest, weight);
            }
        }
    }

    return total - 2 * closest;
}

int main()
{
    use_io_optimizations();

    unsigned int wires;
    cin >> wires;

    unsigned int total = 0;
    vector<unsigned int> weights(wires);

    for (unsigned int i = 0; i < wires; ++i)
    {
        cin >> weights[i];
        total += weights[i];
    }

    cout << min_difference(weights, total) << '\n';

    return 0;
}
