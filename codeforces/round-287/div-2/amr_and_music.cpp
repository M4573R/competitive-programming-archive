#include <algorithm>
#include <iostream>
#include <utility>
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

    unsigned int instruments;
    unsigned int days;

    cin >> instruments >> days;

    vector<pair<unsigned int, unsigned int>> times(instruments);

    for (unsigned int i {0}; i < instruments; ++i)
    {
        cin >> times[i].first;
        times[i].second = i + 1;
    }

    sort(times.begin(), times.end());

    vector<unsigned int> chosen;

    for (unsigned int i {0}; i < instruments && times[i].first <= days; ++i)
    {
        chosen.push_back(times[i].second);
        days -= times[i].first;
    }

    cout << chosen.size() << '\n';

    for (auto i = chosen.cbegin(); i != chosen.cend(); ++i)
    {
        cout << *i << (i + 1 != chosen.cend() ? ' ' : '\n');
    }

    return 0;
}
