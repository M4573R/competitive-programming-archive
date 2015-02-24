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

    vector<string> houses {
        "Slytherin",
        "Hufflepuff",
        "Gryffindor",
        "Ravenclaw"
    };

    map<string, vector<string>> house_members {
        {"Slytherin",  {}},
        {"Hufflepuff", {}},
        {"Gryffindor", {}},
        {"Ravenclaw",  {}}
    };

    unsigned int students;
    cin >> students;
    cin.get();

    for (unsigned int i {0}; i < students; ++i)
    {
        string name;
        getline(cin, name);

        string house;
        cin >> house;
        cin.get();

        house_members[house].push_back(name);
    }

    for (const auto& house : houses)
    {
        cout << house << ":\n";

        for (const auto& member : house_members[house])
        {
            cout << member << '\n';
        }

        cout << '\n';
    }

    return 0;
}
