#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using Node = unsigned int;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

pair<unsigned int, Node>
optimal_outcome(const vector<set<pair<unsigned int, Node>>>& adjacency_list)
{
    Node node          {0};
    unsigned int units {0};

    while (!adjacency_list[node].empty())
    {
        auto optimal_move = adjacency_list[node].crbegin();

        node   = optimal_move->second;
        units += optimal_move->first;
    }

    return {units, node};
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {1}; i <= test_cases; ++i)
    {
        unsigned int nodes, edges;
        cin >> nodes >> edges;

        vector<unsigned int> units(nodes);

        for (unsigned int j {0}; j < nodes; ++j)
        {
            cin >> units[j];
        }

        vector<set<pair<unsigned int, Node>>> adjacency_list(nodes);

        for (unsigned int j {0}; j < edges; ++j)
        {
            Node source;
            Node destination;

            cin >> source >> destination;

            adjacency_list[source].insert(make_pair(units[destination],
                                                    destination));
        }

        pair<unsigned int, Node> outcome {optimal_outcome(adjacency_list)};

        cout << "Case " << i << ": "
             << outcome.first  << ' '
             << outcome.second << '\n';
    }

    return 0;
}
