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

int main()
{
    use_io_optimizations();

    for (unsigned int group {0}, people; cin >> people; ++group)
    {
        if (group > 0)
        {
            cout << '\n';
        }

        map<string, int> money;
        vector<string> names(people);

        for (auto& name : names)
        {
            cin >> name;
        }

        for (unsigned int i {0}; i < people; ++i)
        {
            string name;
            unsigned int given_money;
            unsigned int receivers;

            cin >> name >> given_money >> receivers;

            if (receivers != 0)
            {
                money[name] += given_money % receivers - given_money;

                for (unsigned int j {0}; j < receivers; ++j)
                {
                    string receiver;
                    cin >> receiver;

                    money[receiver] += given_money / receivers;
                }
            }
        }

        for (const auto& name : names)
        {
            cout << name << ' ' << money[name] << '\n';
        }
    }


    return 0;
}
