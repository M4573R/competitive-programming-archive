#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using AdjacencyList = vector<vector<pair<unsigned int, unsigned int>>>;

constexpr unsigned int infinity {UINT_MAX};

constexpr unsigned int source_processor {0};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> dijkstra(const AdjacencyList& graph,
                              unsigned int start_node)
{
    vector<unsigned int> distances(graph.size(), infinity);
    distances[start_node] = 0;

    priority_queue<
        pair<unsigned int, unsigned int>,
        vector<pair<unsigned int, unsigned int>>,
        greater<pair<unsigned int, unsigned int>>
    > cut;

    cut.push(make_pair(0, start_node));

    while (!cut.empty())
    {
        unsigned int closest_node {cut.top().second};
        unsigned int to_closest   {cut.top().first};

        cut.pop();

        if (distances[closest_node] < to_closest)
        {
            continue;
        }

        for (const auto& adjacent : graph[closest_node])
        {
            unsigned int adjacent_node {adjacent.first};
            unsigned int edge_weight   {adjacent.second};

            if (distances[adjacent_node] > to_closest + edge_weight)
            {
                distances[adjacent_node] = to_closest + edge_weight;
                cut.push(make_pair(distances[adjacent_node], adjacent_node));
            }
        }
    }

    return distances;
}

int main()
{
    use_io_optimizations();

    unsigned int processors;
    cin >> processors;

    AdjacencyList graph(processors);

    for (unsigned int i {1}; i < processors; ++i)
    {
        for (unsigned int j {0}; j < i; ++j)
        {
            string communication_time;
            cin >> communication_time;

            if (communication_time != "x")
            {
                graph[i].push_back(
                    make_pair(j, atoi(communication_time.c_str()))
                );

                graph[j].push_back(
                    make_pair(i, atoi(communication_time.c_str()))
                );
            }
        }
    }

    vector<unsigned int> times {dijkstra(graph, source_processor)};

    cout << *max_element(times.begin(), times.end()) << '\n';

    return 0;
}
