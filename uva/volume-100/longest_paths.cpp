#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> topsort(const vector<vector<unsigned int>>& graph,
                             vector<unsigned int>& indegrees)
{
    vector<unsigned int> sorted;
    vector<unsigned int> remaining;

    for (vector<unsigned int>::size_type i {1}; i < indegrees.size(); ++i)
    {
        if (indegrees[i] == 0)
        {
            remaining.push_back(i);
        }
    }

    while (!remaining.empty())
    {
        unsigned int current {remaining.back()};

        remaining.pop_back();
        sorted.push_back(current);

        for (auto adjacent : graph[current])
        {
            --indegrees[adjacent];

            if (indegrees[adjacent] == 0)
            {
                remaining.push_back(adjacent);
            }
        }
    }

    return sorted;
}

int main()
{
    use_io_optimizations();

    for (unsigned int vertices, test {1}; cin >> vertices && vertices; ++test)
    {
        unsigned int source;
        cin >> source;

        vector<vector<unsigned int>> graph(vertices + 1);
        vector<unsigned int>         indegrees(vertices + 1);

        for (unsigned int from, to; cin >> from >> to && from && to; )
        {
            graph[from].push_back(to);
            ++indegrees[to];
        }

        vector<unsigned int> sorted {topsort(graph, indegrees)};
        vector<unsigned int> distances(vertices + 1);

        for (auto vertex : sorted)
        {
            if (vertex == source || distances[vertex] != 0)
            {
                for (auto adjacent : graph[vertex])
                {
                    distances[adjacent] = max(distances[adjacent],
                                              distances[vertex] + 1);
                }
            }
        }

        auto max_distance = max_element(distances.cbegin() + 1, distances.cend());

        cout << "Case "                  << test          << ": "
             << "The longest path from " << source        << " "
             << "has length "            << *max_distance << ", "
             << "finishing at "          << max_distance - distances.cbegin()
             << ".\n\n";
    }

    return 0;
}
