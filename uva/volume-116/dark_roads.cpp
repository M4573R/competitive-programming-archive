#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class UnionFind
{
public:
    UnionFind(unsigned int items):
        parents(items),
        ranks(items),
        components(items)
    {
        for (unsigned int i {0}; i < components; ++i)
        {
            parents[i] = i;
        }
    }

    void link(unsigned int item_a, unsigned int item_b)
    {
        unsigned int root_a {find(item_a)};
        unsigned int root_b {find(item_b)};

        if (root_a == root_b)
        {
            return;
        }

        if (ranks[root_a] < ranks[root_b])
        {
            parents[root_a] = root_b;
        }
        else if (ranks[root_a] > ranks[root_b])
        {
            parents[root_b] = root_a;
        }
        else
        {
            parents[root_b] = root_a;
            ++ranks[root_a];
        }

        --components;
    }

    unsigned int find(unsigned int item)
    {
        unsigned int root {item};

        while (root != parents[root])
        {
            root = parents[root];
        }

        while (item != root)
        {
            unsigned int parent {parents[item]};

            parents[item] = root;
            item          = parent;
        }

        return root;
    }

    bool connected(unsigned int item_a, unsigned int item_b)
    {
        return find(item_a) == find(item_b);
    }

private:
    vector<unsigned int> parents;
    vector<unsigned int> ranks;

    unsigned int components;
};

struct Edge
{
    unsigned int source;
    unsigned int destination;
    unsigned int weight;

    Edge() = default;

    Edge(unsigned int source, unsigned int destination, unsigned int weight):
        source(source),
        destination(destination),
        weight(weight)
    { }
};

bool operator<(const Edge& left, const Edge& right)
{
    return left.weight < right.weight;
}

unsigned int relaxed_cost(vector<Edge>& edges, unsigned int nodes)
{
    unsigned int cost {0};
    UnionFind forest(nodes);

    sort(edges.begin(), edges.end());

    for (unsigned int i {0}, added {0}; added < nodes - 1; ++i)
    {
        if (!forest.connected(edges[i].source, edges[i].destination))
        {
            forest.link(edges[i].source, edges[i].destination);
            cost += edges[i].weight;
            ++added;
        }
    }

    return cost;
}

int main()
{
    use_io_optimizations();

    unsigned int junctions;
    unsigned int roads;

    while (cin >> junctions >> roads && !(junctions == 0 && roads == 0))
    {
        unsigned int initial_cost {0};
        vector<Edge> edges(roads);

        for (auto& edge : edges)
        {
            cin >> edge.source >> edge.destination >> edge.weight;
            initial_cost += edge.weight;
        }

        cout << initial_cost - relaxed_cost(edges, junctions) << '\n';
    }

    return 0;
}
