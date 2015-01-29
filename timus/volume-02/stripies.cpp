#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
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

    cout << fixed << setprecision(2);

    unsigned int stripies;
    cin >> stripies;

    vector<unsigned int> weights(stripies);

    for (auto& weight : weights)
    {
        cin >> weight;
    }

    sort(weights.begin(), weights.end(), greater<unsigned int>());

    double min_total_weight {weights.front()};

    for (unsigned int i {1}; i < stripies; ++i)
    {
        min_total_weight = 2 * sqrt(min_total_weight * weights[i]);
    }

    cout << min_total_weight << '\n';

    return 0;
}
