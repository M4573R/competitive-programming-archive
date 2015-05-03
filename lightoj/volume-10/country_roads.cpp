#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

typedef vector< pair<unsigned int, unsigned int> > NodesList;
typedef vector<NodesList>                          AdjacencyList;

typedef priority_queue< pair<unsigned int, unsigned int>,
                        vector< pair<unsigned int, unsigned int> >,
                        greater< pair<unsigned int, unsigned int> > > MinHeap;

const unsigned int infinity = numeric_limits<unsigned int>::max();

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);

    // Uncommenting this line causes a Runtime Error
    // cin.tie(NULL);
}

void read_input(unsigned int& cities,
                unsigned int& roads,
                unsigned int& target,
                AdjacencyList& graph)
{
    cin >> cities >> roads;

    graph.resize(cities);

    for (unsigned int i = 0; i < roads; ++i)
    {
        unsigned int source;
        unsigned int destination;
        unsigned int cost;

        cin >> source >> destination >> cost;

        graph[source].push_back(make_pair(destination, cost));
        graph[destination].push_back(make_pair(source, cost));
    }

    cin >> target;
}

void write_output(unsigned int test, const vector<unsigned int>& costs)
{
    cout << "Case " << test << ":\n";

    for (vector<unsigned int>::size_type i = 0; i < costs.size(); ++i)
    {
        if (costs[i] == infinity)
        {
            cout << "Impossible";
        }
        else
        {
            cout << costs[i];
        }

        cout << '\n';
    }
}

vector<unsigned int> min_costs(const AdjacencyList& graph, unsigned int source)
{
    vector<unsigned int> costs(graph.size(), infinity);
    costs[source] = 0;

    MinHeap cut;
    cut.push(make_pair(0, source));

    while (!cut.empty())
    {
        unsigned int closest    = cut.top().second;
        unsigned int to_closest = cut.top().first;

        cut.pop();

        if (costs[closest] < to_closest)
        {
            continue;
        }

        for (NodesList::size_type i = 0; i < graph[closest].size(); ++i)
        {
            unsigned int adjacent_node = graph[closest][i].first;
            unsigned int adjacent_cost = graph[closest][i].second;

            if (costs[adjacent_node] > max(to_closest, adjacent_cost))
            {
                costs[adjacent_node] = max(to_closest, adjacent_cost);
                cut.push(make_pair(costs[adjacent_node], adjacent_node));
            }
        }
    }

    return costs;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int cities;
        unsigned int roads;
        unsigned int target;

        AdjacencyList graph;

        read_input(cities, roads, target, graph);
        write_output(test, min_costs(graph, target));
    }

    return 0;
}
