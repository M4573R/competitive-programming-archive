#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>

using namespace std;

using Node          = string;
using AdjacencyList = map<Node, set<Node>>;

const Node start_node {"Isenbaev"};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

map<Node, unsigned int> reachable_distances(AdjacencyList& graph,
                                            const Node& from)
{
    queue<Node> levels;
    levels.push(from);

    set<Node> visited;
    visited.insert(from);

    map<Node, unsigned int> distances;
    distances[from] = 0;

    while (!levels.empty())
    {
        Node current {levels.front()};
        levels.pop();

        for (const Node& adjacent : graph[current])
        {
            if (visited.find(adjacent) == visited.end())
            {
                levels.push(adjacent);
                visited.insert(adjacent);

                distances[adjacent] = distances[current] + 1;
            }
        }
    }

    return distances;
}

int main()
{
    use_io_optimizations();

    AdjacencyList graph;

    unsigned int teams;
    cin >> teams;

    for (unsigned int i {0}; i < teams; ++i)
    {
        Node first;
        Node second;
        Node third;

        cin >> first >> second >> third;

        graph[first].insert(second);
        graph[first].insert(third);

        graph[second].insert(first);
        graph[second].insert(third);

        graph[third].insert(first);
        graph[third].insert(second);
    }

    map<Node, unsigned int> distances;

    if (graph.find(start_node) != graph.end())
    {
        distances = reachable_distances(graph, start_node);
    }

    for (const auto& node_and_adjacent : graph)
    {
        const Node& node {node_and_adjacent.first};

        cout << node << ' ';

        if (distances.find(node) == distances.end())
        {
            cout << "undefined";
        }
        else
        {
            cout << distances[node];
        }

        cout << '\n';
    }

    return 0;
}
