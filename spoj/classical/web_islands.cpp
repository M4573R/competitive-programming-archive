#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void visit(unsigned int node,
           const vector<vector<unsigned int>>& graph,
           vector<bool>& visited,
           stack<unsigned int>& order)
{
    visited[node] = true;

    for (auto adjacent : graph[node])
    {
        if (!visited[adjacent])
        {
            visit(adjacent, graph, visited, order);
        }
    }

    order.push(node);
}

unsigned int component_id(unsigned int node,
                          unsigned int component,
                          const vector<vector<unsigned int>>& graph,
                          vector<bool>& visited,
                          vector<unsigned int>& components)
{
    visited[node]    = true;
    components[node] = component;

    unsigned int id {node};

    for (auto adjacent : graph[node])
    {
        if (!visited[adjacent])
        {
            id = min(id, component_id(adjacent,
                                      component,
                                      graph,
                                      visited,
                                      components));
        }
    }

    return id;
}

void kosaraju(const vector<vector<unsigned int>>& graph,
              const vector<vector<unsigned int>>& reversed,
              vector<unsigned int>& components,
              vector<unsigned int>& components_ids)
{
    vector<bool> visited(graph.size());
    stack<unsigned int> order;

    for (unsigned int node {0}; node < graph.size(); ++node)
    {
        if (!visited[node])
        {
            visit(node, graph, visited, order);
        }
    }

    fill(visited.begin(), visited.end(), false);

    for (unsigned int component {0}; !order.empty(); order.pop())
    {
        if (!visited[order.top()])
        {
            components_ids.push_back(component_id(order.top(),
                                                  component++,
                                                  reversed,
                                                  visited,
                                                  components));
        }
    }
}

int main()
{
    use_io_optimizations();

    unsigned int pages;
    unsigned int links;

    cin >> pages >> links;

    vector<vector<unsigned int>> graph(pages);
    vector<vector<unsigned int>> reversed(pages);

    for (unsigned int i {0}; i < links; ++i)
    {
        unsigned int source;
        unsigned int destination;

        cin >> source >> destination;

        graph[source].push_back(destination);
        reversed[destination].push_back(source);
    }

    vector<unsigned int> components(pages);
    vector<unsigned int> components_ids;

    kosaraju(graph, reversed, components, components_ids);

    for (auto component : components)
    {
        cout << components_ids[component] << '\n';
    }

    return 0;
}
