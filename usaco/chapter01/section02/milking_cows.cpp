/*
    ID:   gsshopo1
    PROG: milk2
    LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    ifstream fin  {"milk2.in"};
    ofstream fout {"milk2.out"};

    unsigned int farmers;
    fin >> farmers;

    vector<pair<unsigned int, unsigned int>> intervals(farmers);

    for (unsigned int i {0}; i < farmers; ++i)
    {
        fin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end());

    unsigned int lower {intervals[0].first};
    unsigned int upper {intervals[0].second};

    unsigned int max_milking {upper - lower};
    unsigned int max_idle    {0};

    for (unsigned int i {1}; i < farmers; ++i)
    {
        if (upper < intervals[i].first)
        {
            max_idle = max(max_idle, intervals[i].first - upper);

            lower = intervals[i].first;
            upper = intervals[i].second;

            max_milking = max(max_milking, upper - lower);
        }
        else
        {
            upper       = max(upper, intervals[i].second);
            max_milking = max(max_milking, upper - lower);
        }
    }

    fout << max_milking << ' ' << max_idle << '\n';

    return 0;
}
