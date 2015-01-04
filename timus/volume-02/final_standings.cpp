#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Team
{
    unsigned int id;
    unsigned int solved_problems;

    Team() = default;

    bool operator<(const Team& other) const
    {
        return solved_problems > other.solved_problems;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int teams_count;
    cin >> teams_count;

    vector<Team> teams(teams_count);

    for (auto& team : teams)
    {
        cin >> team.id >> team.solved_problems;
    }

    stable_sort(teams.begin(), teams.end());

    for (const auto& team : teams)
    {
        cout << team.id << ' ' << team.solved_problems << '\n';
    }

    return 0;
}
