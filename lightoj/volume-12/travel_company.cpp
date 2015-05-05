#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Edge
{
    unsigned int from;
    unsigned int to;

    int cost;
};

bool has_negative_cycle(const vector<Edge>& edges, unsigned int nodes_count)
{
    vector<int> costs(nodes_count);

    for (unsigned int i = 0; i < nodes_count - 1; ++i)
    {
        for (unsigned int j = 0; j < edges.size(); ++j)
        {
            if (costs[edges[j].from] + edges[j].cost < costs[edges[j].to])
            {
                costs[edges[j].to] = costs[edges[j].from] + edges[j].cost;
            }
        }
    }

    for (unsigned int i = 0; i < edges.size(); ++i)
    {
        if (costs[edges[i].from] + edges[i].cost < costs[edges[i].to])
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

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int nodes_count;
        unsigned int edges_count;
        unsigned int ratio;

        cin >> nodes_count >> edges_count >> ratio;

        vector<Edge> edges(edges_count);

        for (unsigned int i = 0; i < edges_count; ++i)
        {
            cin >> edges[i].from >> edges[i].to;

            int incomes;
            int expenses;

            cin >> incomes >> expenses;

            edges[i].cost = expenses * ratio - incomes;
        }

        cout << "Case " << test << ": "
             << (has_negative_cycle(edges, nodes_count) ? "YES" : "NO") << '\n';
    }

    return 0;
}
