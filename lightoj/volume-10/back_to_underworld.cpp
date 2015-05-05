#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const unsigned int max_node = 20000;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

unsigned int traverse(const vector< vector<unsigned int> >& graph,
                      vector<bool>& visited,
                      unsigned int start_node)
{
    queue <unsigned int> levels;
    vector<unsigned int> colors(max_node + 1, 2);

    colors[start_node]  = 0;
    visited[start_node] = true;
    levels.push(start_node);

    while (!levels.empty())
    {
        unsigned int current = levels.front();
        levels.pop();

        for (unsigned int i = 0; i < graph[current].size(); ++i)
        {
            unsigned int adjacent = graph[current][i];

            if (!visited[adjacent])
            {
                colors[adjacent]  = (colors[current] + 1) % 2;
                visited[adjacent] = true;
                levels.push(adjacent);
            }
        }
    }

    return max(count(colors.begin(), colors.end(), 0),
               count(colors.begin(), colors.end(), 1));
}

unsigned int max_members(const vector< vector<unsigned int> >& graph)
{
    unsigned int members = 0;
    vector<bool> visited(max_node + 1);

    for (unsigned int node = 0; node <= max_node; ++node)
    {
        if (!graph[node].empty() && !visited[node])
        {
            members += traverse(graph, visited, node);
        }
    }

    return members;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int edges;
        cin >> edges;

        vector< vector<unsigned int> > graph(max_node + 1);

        for (unsigned int i = 0; i < edges; ++i)
        {
            unsigned int from;
            unsigned int to;

            cin >> from >> to;

            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        cout << "Case " << test << ": " << max_members(graph) << '\n';
    }

    return 0;
}
