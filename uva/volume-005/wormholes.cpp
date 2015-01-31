#include <iostream>
#include <limits>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Edge
{
    unsigned int source;
    unsigned int destination;
    int weight;
};

bool has_negative_cycle(const vector<Edge>& edges, int nodes)
{
    vector<int> distances(nodes, numeric_limits<int>::max());
    distances[0] = 0;

    for (unsigned int i {0}; i < nodes - 1; ++i)
    {
        for (auto& edge : edges)
        {
            if (distances[edge.source] != numeric_limits<int>::max() &&
                distances[edge.source] + edge.weight < distances[edge.destination])
            {
                distances[edge.destination] = distances[edge.source] + edge.weight;
            }
        }
    }

    for (auto& edge : edges)
    {
        if (distances[edge.source] != numeric_limits<int>::max() &&
            distances[edge.source] + edge.weight < distances[edge.destination])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int star_systems;
        unsigned int wormholes;

        cin >> star_systems >> wormholes;

        vector<Edge> edges(wormholes);

        for (auto& edge : edges)
        {
            cin >> edge.source >> edge.destination >> edge.weight;
        }

        cout << (has_negative_cycle(edges, star_systems) ?
                     "possible" :
                     "not possible")
             << '\n';
    }

    return 0;
}
