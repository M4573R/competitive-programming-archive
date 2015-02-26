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

    void link(unsigned int item, unsigned int another_item)
    {
        unsigned int root_i {find(item)};
        unsigned int root_j {find(another_item)};

        if (root_i == root_j)
        {
            return;
        }

        if (ranks[root_i] < ranks[root_j])
        {
            parents[root_j] = root_i;
        }
        else if (ranks[root_i] > ranks[root_j])
        {
            parents[root_i] = root_j;
        }
        else
        {
            parents[root_i] = root_j;
            ++ranks[root_i];
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

    bool connected(int a, int b)
    {
        return find(a) == find(b);
    }

    unsigned int size() const
    {
        return components;
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

unsigned int mst_weight(vector<Edge>& edges, unsigned int nodes)
{
    unsigned int weight {0};
    UnionFind forest(nodes + 1);

    sort(edges.begin(), edges.end());

    for (unsigned int i {0}, mst_edges {0}; mst_edges < nodes - 1; ++i)
    {
        if (!forest.connected(edges[i].source, edges[i].destination))
        {
            ++mst_edges;
            weight += edges[i].weight;
            forest.link(edges[i].source, edges[i].destination);
        }
    }

    return weight;
}

int main()
{
    use_io_optimizations();

    for (unsigned int test {0}, sites; cin >> sites; ++test)
    {
        if (test > 0)
        {
            cout << '\n';
        }

        unsigned int initial_cost {0};

        for (unsigned int i {0}; i < sites - 1; ++i)
        {
            unsigned int source;
            unsigned int destination;
            unsigned int cost;

            cin >> source >> destination >> cost;
            initial_cost += cost;
        }

        vector<Edge> edges;

        unsigned int additional_lines;
        cin >> additional_lines;

        for (unsigned int i {0}; i < additional_lines; ++i)
        {
            unsigned int source;
            unsigned int destination;
            unsigned int cost;

            cin >> source >> destination >> cost;

            edges.emplace_back(source, destination, cost);
        }

        unsigned int initial_lines;
        cin >> initial_lines;

        for (unsigned int i {0}; i < initial_lines; ++i)
        {
            unsigned int source;
            unsigned int destination;
            unsigned int cost;

            cin >> source >> destination >> cost;

            edges.emplace_back(source, destination, cost);
        }

        cout << initial_cost << '\n' << mst_weight(edges, sites) << '\n';
    }

    return 0;
}
