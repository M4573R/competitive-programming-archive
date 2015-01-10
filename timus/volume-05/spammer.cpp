#include <iostream>
#include <map>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int submissions;
    cin >> submissions;

    map<string, unsigned int> team_submissions;

    for (unsigned int i {0}; i < submissions; ++i)
    {
        string team;
        cin >> team;

        ++team_submissions[team];
    }

    for (const auto& team_and_submissions : team_submissions)
    {
        if (team_and_submissions.second > 1)
        {
            cout << team_and_submissions.first << '\n';
        }
    }

    return 0;
}
