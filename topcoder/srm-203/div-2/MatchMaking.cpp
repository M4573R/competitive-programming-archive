#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Person
{
    string name;
    string answers;
};

bool operator<(const Person& left, const Person& right)
{
    return left.name < right.name;
}

class MatchMaking
{
public:
    string makeMatch(vector<string> namesWomen,
                     vector<string> answersWomen,
                     vector<string> namesMen,
                     vector<string> answersMen,
                     string queryWoman)
    {
        initialize(namesWomen, answersMen, namesMen, answersMen);
        match_into_couples();

        return men[matches[queryWoman]].name;
    }

private:
    vector<Person> women;
    vector<Person> men;

    map<string, int> matches;

    int couples;

    void initialize(vector<string>& namesWomen,
                    vector<string>& answersWomen,
                    vector<string>& namesMen,
                    vector<string>& answersMen)
    {
        couples = namesWomen.size();

        women.resize(couples);
        men.resize(couples);

        for (int i {0}; i < couples; ++i)
        {
            women[i].name    = namesWomen[i];
            women[i].answers = answersWomen[i];

            men[i].name    = namesMen[i];
            men[i].answers = answersMen[i];
        }

        sort(women.begin(), women.end());
        sort(men.begin(),   men.end());
    }

    void match_into_couples()
    {
        vector<bool> is_man_matched(couples);

        for (int i {0}; i < couples; ++i)
        {
            int max_common {-1};

            for (int j {0}; j < couples; ++j)
            {
                if (!is_man_matched[j])
                {
                    int common {0};

                    for (int k {0}; k < women[i].answers.size(); ++k)
                    {
                        common += (women[i].answers[k] == men[j].answers[k]);
                    }

                    if (common > max_common)
                    {
                        max_common = common;
                        matches[women[i].name] = j;
                    }
                }
            }

            is_man_matched[matches[women[i].name]] = true;
        }
    }
};
