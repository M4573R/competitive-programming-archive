#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using AdjacencyList = vector<vector<pair<unsigned int, unsigned int>>>;

constexpr unsigned int infinity {UINT_MAX};

constexpr unsigned int floors_count {100};
constexpr unsigned int switch_time  {60};
constexpr unsigned int start_floor  {0};

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

    unsigned int elevators;
    unsigned int target_floor;

    while (cin >> elevators >> target_floor)
    {
        vector<unsigned int> speeds(elevators);

        for (unsigned int j {0}; j < elevators; ++j)
        {
            cin >> speeds[j];
        }

        cin.get();

        AdjacencyList graph(floors_count);

        for (unsigned int i {0}; i < elevators; ++i)
        {
            string line;
            getline(cin, line);

            istringstream accessible_floors {line};

            unsigned int current;
            vector<unsigned int> nodes;

            while (accessible_floors >> current)
            {
                nodes.push_back(current);
            }

            for (auto x = nodes.cbegin(); x != nodes.cend() - 1; ++x)
            {
                for (auto y = x + 1; y != nodes.cend(); ++y)
                {
                    graph[*x].push_back(
                        make_pair(*y, (*y - *x) * speeds[i] + switch_time)
                    );

                    graph[*y].push_back(
                        make_pair(*x, (*y - *x) * speeds[i] + switch_time)
                    );
                }
            }
        }

        vector<unsigned int> times {dijkstra(graph, start_floor)};

        if (times[target_floor] == infinity)
        {
            cout << "IMPOSSIBLE";
        }
        else if (times[target_floor] == 0)
        {
            cout << 0;
        }
        else
        {
            cout << times[target_floor] - switch_time;
        }

        cout << '\n';
    }

    return 0;
}
