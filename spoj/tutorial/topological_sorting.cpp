#include <iostream>
#include <set>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> topsort(const vector<vector<unsigned int>>& graph,
                             vector<unsigned int>& in_degrees)
{
    unsigned int added    {0};
    unsigned int vertices {graph.size() - 1};

    set<unsigned int> remaining;
    vector<unsigned int> sorted(vertices);

    for (unsigned int i {1}; i <= vertices; ++i)
    {
        if (in_degrees[i] == 0)
        {
            remaining.insert(i);
        }
    }

    while (!remaining.empty())
    {
        unsigned int current {*remaining.begin()};
        remaining.erase(remaining.begin());

        sorted[added++] = current;

        for (auto adjacent : graph[current])
        {
            --in_degrees[adjacent];

            if (in_degrees[adjacent] == 0)
            {
                remaining.insert(adjacent);
            }
        }
    }

    return added == vertices ? sorted : vector<unsigned int>{};
}

int main()
{
    use_io_optimizations();

    unsigned int tasks;
    unsigned int relations;

    cin >> tasks >> relations;

    vector<unsigned int> in_degrees(tasks + 1);
    vector<vector<unsigned int>> graph(tasks + 1);

    for (unsigned int i {0}; i < relations; ++i)
    {
        unsigned int prerequisite;
        unsigned int consequent;

        cin >> prerequisite >> consequent;

        graph[prerequisite].push_back(consequent);
        ++in_degrees[consequent];
    }

    vector<unsigned int> sorted {topsort(graph, in_degrees)};

    if (sorted.empty())
    {
        cout << "Sandro fails.";
    }
    else
    {
        for (auto task : sorted)
        {
            cout << task << ' ';
        }
    }

    cout << '\n';

    return 0;
}
