/*
    ID:   gsshopo1
    PROG: barn1
    LANG: C++11
*/

#include <algorithm>
#include <functional>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin  {"barn1.in"};
    ofstream fout {"barn1.out"};

    unsigned int boards;
    unsigned int stalls;
    unsigned int cows;

    fin >> boards >> stalls >> cows;

    vector<unsigned int> occupied_stalls(cows);

    for (unsigned int i {0}; i < cows; ++i)
    {
        fin >> occupied_stalls[i];
    }

    sort(occupied_stalls.begin(), occupied_stalls.end(), greater<unsigned int>());

    vector<unsigned int> gaps;

    for (unsigned int i {0}; i < cows - 1; ++i)
    {
        if (occupied_stalls[i] - occupied_stalls[i + 1] > 1)
        {
            gaps.push_back(occupied_stalls[i] - occupied_stalls[i + 1] - 1);
        }
    }

    sort(gaps.begin(), gaps.end(), greater<unsigned int>());

    unsigned int non_blocked_stalls {occupied_stalls.back() - 1 +
                                     stalls - occupied_stalls.front()};

    for (unsigned int i {0}; i < gaps.size() && i < boards - 1; ++i)
    {
        non_blocked_stalls += gaps[i];
    }

    fout << stalls - non_blocked_stalls << '\n';

    return 0;
}
