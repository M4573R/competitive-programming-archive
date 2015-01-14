#include <algorithm>
#include <iostream>
#include <utility>
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

    unsigned int exams;
    cin >> exams;

    vector<pair<unsigned int, unsigned int>> dates(exams);

    for (unsigned int i {0}; i < exams; ++i)
    {
        cin >> dates[i].first >> dates[i].second;
    }

    sort(dates.begin(), dates.end());

    unsigned int min_day {1};

    for (unsigned int i {0}; i < exams; ++i)
    {
        if (dates[i].second < min_day)
        {
            min_day = dates[i].first;
        }
        else
        {
            min_day = dates[i].second;
        }
    }

    cout << min_day << '\n';

    return 0;
}
