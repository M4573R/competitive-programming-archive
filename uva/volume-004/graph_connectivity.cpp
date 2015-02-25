#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void visit(unsigned int node,
           const vector<vector<unsigned int>>& graph,
           vector<bool>& visited)
{
    visited[node] = true;

    for (auto adjacent : graph[node])
    {
        if (!visited[adjacent])
        {
            visit(adjacent, graph, visited);
        }
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        char max_node;
        cin >> max_node;
        cin.get();

        unsigned int nodes = max_node - 'A' + 1;
        vector<vector<unsigned int>> graph(nodes);

        for (string edge; getline(cin, edge) && !edge.empty(); )
        {
            graph[edge.front() - 'A'].push_back(edge.back()  - 'A');
            graph[edge.back()  - 'A'].push_back(edge.front() - 'A');
        }

        vector<bool> visited(nodes);

        unsigned int components {0};

        for (unsigned int node {0}; node < nodes; ++node)
        {
            if (!visited[node])
            {
                ++components;
                visit(node, graph, visited);
            }
        }

        cout << components << '\n';

        if (test < test_cases - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
