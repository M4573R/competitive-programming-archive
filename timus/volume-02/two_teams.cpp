#include <iostream>
#include <set>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int members;
    cin >> members;

    set<unsigned int> first_team;

    for (unsigned int member {1}; member <= members; ++member)
    {
        bool has_mate_in_first_team {false};

        for (unsigned int mate; cin >> mate && mate != 0;)
        {
            if (first_team.count(mate))
            {
                has_mate_in_first_team = true;
            }
        }

        if (!has_mate_in_first_team)
        {
            first_team.insert(member);
        }
    }

    cout << first_team.size() << '\n';

    for (auto player = first_team.cbegin(); player != first_team.cend(); ++player)
    {
        if (player != first_team.begin())
        {
            cout << ' ';
        }

        cout << *player;
    }

    cout << '\n';

    return 0;
}
