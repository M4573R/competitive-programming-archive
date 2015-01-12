#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

string::size_type total_knowledge(const string& first, const string& second)
{
    string::size_type knowledge {0};

    for (string::size_type i {0}; i < first.size(); ++i)
    {
        if (first[i] == '1' || second[i] == '1')
        {
            ++knowledge;
        }
    }

    return knowledge;
}

int main()
{
    use_io_optimizations();

    unsigned int people;
    unsigned int topics;

    cin >> people >> topics;

    vector<string> people_knowledge(people);

    for (auto& knowledge : people_knowledge)
    {
        cin >> knowledge;
    }

    unsigned int max_team_knowledge  {0};
    unsigned int max_knowledge_teams {0};

    for (unsigned int i {0}; i < people - 1; ++i)
    {
        for (unsigned int j {i + 1}; j < people; ++j)
        {
            unsigned int knowledge {total_knowledge(people_knowledge[i],
                                                    people_knowledge[j])};

            if (knowledge > max_team_knowledge)
            {
                max_team_knowledge  = knowledge;
                max_knowledge_teams = 1;
            }
            else if (knowledge == max_team_knowledge)
            {
                ++max_knowledge_teams;
            }
        }
    }

    cout << max_team_knowledge  << '\n'
         << max_knowledge_teams << '\n';

    return 0;
}
