#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using Node          = unsigned int;
using AdjacencyList = vector<vector<unsigned int>>;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int strongly_connected_components(const AdjacencyList& graph,
                                           unsigned int nodes)
{
    set<Node> visited;
    unsigned int components {0};

    for (Node node {1}; node <= nodes; ++node)
    {
        if (visited.find(node) == visited.end())
        {
            ++components;

            queue<unsigned int> levels;
            levels.push(node);

            while (!levels.empty())
            {
                unsigned int current {levels.front()};
                levels.pop();

                for (Node adjacent : graph[current])
                {
                    if (visited.find(adjacent) == visited.end())
                    {
                        levels.push(adjacent);
                        visited.insert(adjacent);
                    }
                }
            }
        }
    }

    return components;
}

int main()
{
    use_io_optimizations();

    unsigned int islands;
    unsigned int tunnels;
    unsigned int bridges;

    cin >> islands >> tunnels >> bridges;

    AdjacencyList graph(islands + 1);

    for (unsigned int i {0}; i < tunnels; ++i)
    {
        Node source;
        Node destination;

        cin >> source >> destination;

        graph[source].push_back(destination);
        graph[destination].push_back(source);
    }

    cout << strongly_connected_components(graph, islands) - 1 << '\n';

    return 0;
}
