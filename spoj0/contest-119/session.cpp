#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const unsigned int infinity = numeric_limits<unsigned int>::max();

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void shortest_paths(vector< vector< pair<unsigned int, unsigned int> > >& graph,
                    int start_node,
                    vector<unsigned int>& distances)
{
    priority_queue<
        pair<unsigned int, unsigned int>,
        vector< pair<unsigned int, unsigned int> >,
        greater< pair<unsigned int, unsigned int> >
    > cut;

    distances[start_node] = 0;
    cut.push(make_pair(0, start_node));

    while (!cut.empty())
    {
        unsigned int closest     = cut.top().second;
        unsigned int to_closest  = cut.top().first;

        cut.pop();

        if (to_closest > distances[closest])
        {
            continue;
        }

        for (unsigned int i = 0; i < graph[closest].size(); ++i)
        {
            unsigned int adjacent_node = graph[closest][i].first;
            unsigned int edge_weight   = graph[closest][i].second;

            if (distances[adjacent_node] > distances[closest] + edge_weight)
            {
                distances[adjacent_node] = distances[closest] + edge_weight;
                cut.push(make_pair(distances[adjacent_node], adjacent_node));
            }
        }
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned int nodes;
        unsigned int edges;

        cin >> nodes >> edges;

        vector< vector< pair<unsigned int, unsigned int> > > graph(nodes + 1);

        for (unsigned int i = 0; i < edges; ++i)
        {
            unsigned int source;
            unsigned int destination;
            unsigned int weight;

            cin >> source >> destination >> weight;

            graph[destination].push_back(make_pair(source, weight));
        }

        vector<unsigned int> distances(nodes + 1, infinity);
        shortest_paths(graph, nodes, distances);

        for (unsigned int i = 1; i < nodes; ++i)
        {
            if (distances[i] == infinity)
            {
                cout << -1;
            }
            else
            {
                cout << distances[i];
            }

            if (i < nodes - 1)
            {
                cout << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
