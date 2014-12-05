/*
    ID:   gsshopo1
    PROG: beads
    LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using Group = pair<char, unsigned int>;

constexpr char red   {'r'};
constexpr char blue  {'b'};
constexpr char white {'w'};
constexpr char none  {'n'};

vector<Group> bead_groups(const string& necklace)
{
    vector<Group> groups;
    string double_necklace {necklace + necklace};

    for (string::size_type i {0}; i < double_necklace.size(); )
    {
        char bead {double_necklace[i]};
        unsigned int group_size {0};

        for (; i < double_necklace.size() && double_necklace[i] == bead; ++i)
        {
            ++group_size;
        }

        groups.push_back(make_pair(bead, group_size));
    }

    return groups;
}

unsigned int max_collected_beads(const vector<Group>& groups)
{
    unsigned int max_beads {0};

    for (vector<Group>::size_type i {0}; i < groups.size(); )
    {
        unsigned int beads {0};

        char last      {none};
        char forbidden {none};

        for (; i < groups.size() && groups[i].first != forbidden; ++i)
        {
            beads += groups[i].second;

            if (groups[i].first != white)
            {
                if (last != groups[i].first)
                {
                    forbidden = last;
                }

                last = groups[i].first;
            }
        }

        max_beads = max(max_beads, beads);

        if (i >= groups.size())
            break;

        for (char bead {groups[i].first}; groups[i - 1].first != bead; --i)
        { }
    }

    return max_beads;
}

int main()
{
    ifstream fin  {"beads.in"};
    ofstream fout {"beads.out"};

    unsigned int necklace_beads;
    fin >> necklace_beads;

    string necklace;
    fin >> necklace;

    fout << min(max_collected_beads(bead_groups(necklace)),
                necklace_beads)
         << '\n';

    return 0;
}
