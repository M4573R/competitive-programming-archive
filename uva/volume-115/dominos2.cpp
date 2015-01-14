#include <iostream>
#include <queue>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void breadth_first_traversal(const vector<vector<unsigned int>>& graph,
                             vector<bool>& visited,
                             unsigned int start_node)
{
    queue<unsigned int> levels;
    levels.push(start_node);

    while (!levels.empty())
    {
        unsigned int current_node {levels.front()};
        levels.pop();

        visited[current_node] = true;

        for (auto adjacent_node : graph[current_node])
        {
            if (!visited[adjacent_node])
            {
                levels.push(adjacent_node);
            }
        }
    }
}

unsigned int knocked_tiles(const vector<vector<unsigned int>>& graph,
                           const vector<unsigned int>& start_nodes)
{
    vector<bool> visited(graph.size());

    for (auto node : start_nodes)
    {
        breadth_first_traversal(graph, visited, node);
    }

    unsigned int knocked {0};

    for (auto is_visited : visited)
    {
        if (is_visited)
        {
            ++knocked;
        }
    }

    return knocked;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int domino_tiles;
        unsigned int connections;
        unsigned int knocked_by_hand;

        cin >> domino_tiles >> connections >> knocked_by_hand;

        vector<vector<unsigned int>> graph(domino_tiles + 1);

        for (unsigned int j {0}; j < connections; ++j)
        {
            unsigned int source;
            unsigned int destination;

            cin >> source >> destination;

            graph[source].push_back(destination);
        }

        vector<unsigned int> start_nodes(knocked_by_hand);

        for (unsigned int j {0}; j < knocked_by_hand; ++j)
        {
            cin >> start_nodes[j];
        }

        cout << knocked_tiles(graph, start_nodes) << '\n';
    }

    return 0;
}
