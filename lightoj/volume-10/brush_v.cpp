#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef vector< vector< pair<unsigned int, unsigned int> > > AdjacencyList;

typedef priority_queue<
                     pair<unsigned int, unsigned int>,
            vector < pair<unsigned int, unsigned int> >,
            greater< pair<unsigned int, unsigned int> >
        > MinHeap;

const unsigned int infinity = numeric_limits<unsigned int>::max();

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_input(AdjacencyList& graph)
{
    unsigned int nodes;
    unsigned int edges;

    cin >> nodes >> edges;

    graph.resize(nodes);

    for (unsigned int i = 0; i < edges; ++i)
    {
        unsigned int from;
        unsigned int to;
        unsigned int distance;

        cin >> from >> to >> distance;

        graph[from - 1].push_back(make_pair(to   - 1, distance));
        graph[to   - 1].push_back(make_pair(from - 1, distance));
    }
}

void write_output(unsigned int test, unsigned int distance)
{
    cout << "Case " << test << ": ";

    if (distance == infinity)
    {
        cout << "Impossible";
    }
    else
    {
        cout << distance;
    }

    cout << '\n';
}

unsigned int min_distance(const AdjacencyList& graph)
{
    vector<unsigned int> distances(graph.size(), infinity);
    MinHeap cut;

    distances[0] = 0;
    cut.push(make_pair(0, 0));

    while (!cut.empty())
    {
        unsigned int closest    = cut.top().second;
        unsigned int to_closest = cut.top().first;

        cut.pop();

        if (distances[closest] < to_closest)
        {
            continue;
        }

        for (unsigned int i = 0; i < graph[closest].size(); ++i)
        {
            unsigned int adjacent = graph[closest][i].first;
            unsigned int distance = graph[closest][i].second;

            if (distances[adjacent] > to_closest + distance)
            {
                distances[adjacent] = to_closest + distance;
                cut.push(make_pair(distances[adjacent], adjacent));
            }
        }
    }

    return distances.back();
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        AdjacencyList graph;

        read_input(graph);
        write_output(test, min_distance(graph));
    }

    return 0;
}
