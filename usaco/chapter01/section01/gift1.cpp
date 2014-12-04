/*
    ID:   gsshopo1
    PROG: gift1
    LANG: C++11
*/

#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ifstream fin  {"gift1.in"};
    ofstream fout {"gift1.out"};

    unsigned int friends_count;
    fin >> friends_count;

    vector<string> friends_names(friends_count);
    unordered_map<string, int> friends_balances;

    for (auto& name : friends_names)
    {
        fin >> name;
    }

    for (unsigned int i {0}; i < friends_count; ++i)
    {
        string giver;
        fin >> giver;

        unsigned int amount;
        unsigned int receivers;

        fin >> amount >> receivers;

        if (receivers != 0)
        {
            unsigned int amount_each {amount / receivers};

            for (unsigned int j {0}; j < receivers; ++j)
            {
                string receiver;
                fin >> receiver;

                friends_balances[receiver] += amount_each;
                friends_balances[giver]    -= amount_each;
            }
        }
    }

    for (const auto& name : friends_names)
    {
        fout << name << ' ' << friends_balances[name] << '\n';
    }

    return 0;
}
