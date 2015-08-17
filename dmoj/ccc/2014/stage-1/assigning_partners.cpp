#include <iostream>
#include <set>
#include <string>
#include <utility>
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

    unsigned int students;
    cin >> students;

    vector<string> names(students);

    for (auto& name : names)
    {
        cin >> name;
    }

    set<pair<string, string>> pairs;

    for (unsigned int i {0}; i < students; ++i)
    {
        string partner;
        cin >> partner;

        if (names[i] < partner)
        {
            pairs.emplace(names[i], partner);
        }
        else
        {
            pairs.emplace(partner, names[i]);
        }
    }

    cout << (2 * pairs.size() == students ? "good" : "bad") << '\n';

    return 0;
}
