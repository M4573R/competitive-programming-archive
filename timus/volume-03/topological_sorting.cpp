#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int subjects;
    unsigned int limitations;

    cin >> subjects >> limitations;

    vector<unsigned int> in_degrees(subjects + 1);
    vector<vector<unsigned int>> graph(subjects + 1);

    for (unsigned int i {0}; i < limitations; ++i)
    {
        unsigned int prerequisite;
        unsigned int consequent;

        cin >> prerequisite >> consequent;

        graph[prerequisite].push_back(consequent);
        ++in_degrees[consequent];
    }

    for (unsigned int i {0}; i < subjects; ++i)
    {
        unsigned int subject;
        cin >> subject;

        if (in_degrees[subject] != 0)
        {
            cout << "NO\n";
            return 0;
        }

        for (auto adjacent : graph[subject])
        {
            --in_degrees[adjacent];
        }
    }

    cout << "YES\n";

    return 0;
}
