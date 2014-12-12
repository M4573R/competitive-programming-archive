/*
    ID:   gsshopo1
    PROG: barn1
    LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

unsigned int boards_for_occupied(const vector<bool>& is_occupied)
{
    unsigned int boards {0};

    bool previous_was_occupied {false};

    for (auto occupied : is_occupied)
    {
        if (occupied && !previous_was_occupied)
        {
            ++boards;
        }

        previous_was_occupied = occupied;
    }

    return boards;
}

vector<unsigned int> gaps_between_occupied(const vector<bool>& is_occupied)
{
    vector<unsigned int> gaps;

    vector<bool>::size_type low  {0};
    vector<bool>::size_type high {is_occupied.size() - 1};

    for (; low < is_occupied.size() && !is_occupied[low]; ++low)
    { }

    for (; high >= 0 && !is_occupied[high]; --high)
    { }

    for (; low <= high; ++low)
    {
        unsigned int gap {0};

        for (; low <= high && !is_occupied[low]; ++low)
        {
            ++gap;
        }

        if (gap > 0)
        {
            gaps.push_back(gap);
        }
    }

    return gaps;
}

int main()
{
    ifstream fin  {"barn1.in"};
    ofstream fout {"barn1.out"};

    unsigned int boards;
    unsigned int stalls;
    unsigned int occupied_stalls;

    fin >> boards >> stalls >> occupied_stalls;

    vector<bool> is_occupied(stalls);

    for (unsigned int i {0}; i < occupied_stalls; ++i)
    {
        unsigned int stall;
        fin >> stall;

        is_occupied[stall - 1] = true;
    }

    unsigned int used_boards {boards_for_occupied(is_occupied)};

    if (used_boards <= boards)
    {
        fout << occupied_stalls << '\n';
    }
    else
    {
        vector<unsigned int> gaps {gaps_between_occupied(is_occupied)};
        sort(gaps.begin(), gaps.end());

        unsigned int blocked_stalls {occupied_stalls};

        for (unsigned int i {0}; used_boards > boards; ++i)
        {
            blocked_stalls += gaps[i];
            --used_boards;
        }

        fout << blocked_stalls << '\n';
    }

    return 0;
}
