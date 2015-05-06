#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_input(unsigned int& nodes,
                unsigned int& edges,
                unsigned int& source,
                unsigned int& destination,
                vector< vector<unsigned int> >& graph)
{
    cin >> nodes >> edges;

    graph.resize(nodes);

    for (unsigned int i = 0; i < edges; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    cin >> source >> destination;
}

void write_ouput(unsigned int test,
                 unsigned int nodes,
                 const vector<unsigned int>& from_source,
                 const vector<unsigned int>& from_destination)
{
    unsigned int min_time = 0;

    for (unsigned int i = 0; i < nodes; ++i)
    {
        min_time = max(min_time, from_source[i] + from_destination[i]);
    }

    cout << "Case " << test << ": " << min_time << '\n';
}

vector<unsigned int> min_times(const vector< vector<unsigned int> >& graph,
                               unsigned int start_node)
{
    vector<bool> visited(graph.size());
    visited[start_node] = true;

    vector<unsigned int> times(graph.size());
    times[start_node] = 0;

    queue<unsigned int> levels;
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
                visited[adjacent] = true;
                times[adjacent] = times[current] + 1;
                levels.push(adjacent);
            }
        }
    }

    return times;
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

        unsigned int source;
        unsigned int destination;

        vector< vector<unsigned int> > graph;

        read_input(nodes,
                   edges,
                   source,
                   destination,
                   graph);

        write_ouput(test,
                    nodes,
                    min_times(graph, source),
                    min_times(graph, destination));
    }

    return 0;
}
