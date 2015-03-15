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

    unsigned int saws_and_logs;
    cin >> saws_and_logs;

    vector<unsigned int> consumption_rates(saws_and_logs);

    for (auto& consumption_rate : consumption_rates)
    {
        cin >> consumption_rate;
    }

    vector<unsigned int> lengths(saws_and_logs);

    for (auto& length : lengths)
    {
        cin >> length;
    }

    sort(consumption_rates.begin(), consumption_rates.end());
    sort(lengths.begin(), lengths.end(), greater<unsigned int>());

    unsigned long long min_energy {0};

    for (unsigned int i {0}; i < saws_and_logs; ++i)
    {
        min_energy += consumption_rates[i] * lengths[i];
    }

    cout << min_energy << '\n';

    return 0;
}
