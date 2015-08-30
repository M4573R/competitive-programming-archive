#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
string determine_medal(unsigned int position)
{
    if (position <= 4)
    {
        return "gold";
    }
    else if (position <= 8)
    {
        return "silver";
    }
    else
    {
        return "bronze";
    }
}

void read_standings(map<string, string>& medals)
{
    for (unsigned int i {1}; i <= 12; ++i)
    {
        string university;
        cin >> university;

        medals[university] = determine_medal(i);
    }
}

int main()
{
    use_io_optimizations();

    map<string, string> medals;
    read_standings(medals);

    unsigned int participants;
    cin >> participants;

    vector<unsigned int> scores(participants);

    for (unsigned int i {0}; i < participants; ++i)
    {
        unsigned int predictions;
        cin >> predictions;

        for (unsigned int j {0}; j < predictions; ++j)
        {
            char delimiter;
            string university;
            string medal;

            cin >> university >> delimiter >> medal;

            if (medals[university] == medal)
            {
                ++scores[i];
            }
        }
    }

    cout << 5 * count(scores.cbegin(), scores.cend(),
                      *max_element(scores.cbegin(), scores.cend()))
         << '\n';

    return 0;
}
