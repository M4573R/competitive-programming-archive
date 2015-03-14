#include <iostream>
#include <map>
#include <set>

using namespace std;

const set<char> valid_ballots {'A', 'B', 'C', 'D', 'E', 'F'};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int ballots;
    cin >> ballots;

    map<char, unsigned int> valid_votes;
    unsigned int spoiled_votes {0};

    for (unsigned int i {0}; i < ballots; ++i)
    {
        char ballot;
        cin >> ballot;

        if (valid_ballots.count(ballot))
        {
            ++valid_votes[ballot];
        }
        else
        {
            ++spoiled_votes;
        }
    }

    cout << valid_votes['A'] << '\n'
         << valid_votes['B'] << '\n'
         << valid_votes['C'] << '\n'
         << valid_votes['D'] << '\n'
         << valid_votes['E'] << '\n'
         << valid_votes['F'] << '\n'
         << spoiled_votes    << '\n';

    return 0;
}
