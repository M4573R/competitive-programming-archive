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

    vector<unsigned int> weights(3);

    for (auto& weight : weights)
    {
        cin >> weight;
    }

    sort(weights.begin(), weights.end());

    cout << weights[1] << '\n';

    return 0;
}
