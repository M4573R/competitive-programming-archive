#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int infinity {INT_MAX};
const int sofia    {1};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dijkstra(const vector<vector<pair<int, int>>>& graph,
              int start_node,
              vector<int>& distances)
{
    distances = vector<int>(graph.size(), infinity);
    distances[start_node] = 0;

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> cut;

    cut.push(make_pair(0, start_node));

    while (!cut.empty())
    {
        int closest_node {cut.top().second};
        int to_closest   {cut.top().first};

        cut.pop();

        if (distances[closest_node] < to_closest)
        {
            continue;
        }

        for (const auto& adjacent : graph[closest_node])
        {
            int adjacent_node {adjacent.first};
            int edge_weight   {adjacent.second};

            if (distances[adjacent_node] > to_closest + edge_weight)
            {
                distances[adjacent_node] = to_closest + edge_weight;
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

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int cities_count;
        unsigned int roads_count;

        cin >> cities_count >> roads_count;

        vector<vector<pair<int, int>>> graph(cities_count + 1);

        for (unsigned int j {0}; j < roads_count; ++j)
        {
            int source;
            int destination;
            int duration;

            cin >> source >> destination >> duration;

            graph[source].push_back(make_pair(destination, duration));
        }

        vector<int> durations;
        dijkstra(graph, sofia, durations);

        cout << (durations.back() == infinity ? -1 : durations.back()) << '\n';
    }

    return 0;
}
