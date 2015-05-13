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

    unsigned int reports;
    cin >> reports;

    vector<pair<unsigned int, unsigned int>> times(reports);

    for (auto& time : times)
    {
        cin >> time.second >> time.first;
    }

    sort(times.begin(), times.end());

    unsigned int attended    {1};
    unsigned int last_finish {times.front().first};

    for (unsigned int i {1}; i < reports; ++i)
    {
        if (last_finish < times[i].second)
        {
            last_finish = times[i].first;
            ++attended;
        }
    }

    cout << attended << '\n';

    return 0;
}
