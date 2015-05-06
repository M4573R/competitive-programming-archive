#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void visit(unsigned int node,
           const vector< vector<unsigned int> >& graph,
           vector<bool>& visited,
           stack<unsigned int>& order)
{
    visited[node] = true;

    for (unsigned int i = 0; i < graph[node].size(); ++i)
    {
        if (!visited[graph[node][i]])
        {
            visit(graph[node][i], graph, visited, order);
        }
    }

    order.push(node);
}

stack<unsigned int> order_nodes(const vector< vector<unsigned int> >& graph)
{
    stack<unsigned int> order;
    vector<bool> visited(graph.size());

    for (unsigned int node = 0; node < graph.size(); ++node)
    {
        if (!visited[node])
        {
            visit(node, graph, visited, order);
        }
    }

    return order;
}

void visit(unsigned int node,
           const vector< vector<unsigned int> >& graph,
           vector<bool>& visited)
{
    visited[node] = true;

    for (unsigned int i = 0; i < graph[node].size(); ++i)
    {
        if (!visited[graph[node][i]])
        {
            visit(graph[node][i], graph, visited);
        }
    }
}

unsigned int min_lights(const vector< vector<unsigned int> >& graph)
{
    stack<unsigned int> order {order_nodes(graph)};
    vector<bool> visited(graph.size());

    unsigned int lights = 0;

    while (!order.empty())
    {
        if (!visited[order.top()])
        {
            visit(order.top(), graph, visited);
            ++lights;
        }

        order.pop();
    }

    return lights;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int nodes;
        unsigned int edges;

        cin >> nodes >> edges;

        vector< vector<unsigned int> > graph(nodes);

        for (int j = 0; j < edges; ++j)
        {
            unsigned int from;
            unsigned int to;

            cin >> from >> to;

            graph[from - 1].push_back(to - 1);
        }

        cout << "Case " << test << ": " << min_lights(graph) << '\n';
    }

    return 0;
}
