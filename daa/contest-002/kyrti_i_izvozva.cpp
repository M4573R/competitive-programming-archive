#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class UnionFind
{
public:
    UnionFind(unsigned int items):
        parents(items),
        ranks(items),
        componenets(items)
    {
        for (unsigned int i = 0; i < componenets; ++i)
        {
            parents[i] = i;
        }
    }

    void link(unsigned int item, unsigned int another_item)
    {
        unsigned int root_i = find(item);
        unsigned int root_j = find(another_item);

        if (root_i == root_j)
        {
            return;
        }

        if (ranks[root_i] < ranks[root_j])
        {
            parents[root_i] = root_j;
        }
        else
        {
            parents[root_j] = root_i;

            if (ranks[root_i] == ranks[root_j])
            {
                ++ranks[root_i];
            }
        }

        --componenets;
    }

    unsigned int find(unsigned int item)
    {
        unsigned int root = item;

        while (root != parents[root])
        {
            root = parents[root];
        }

        while (item != root)
        {
            unsigned int parent = parents[item];

            parents[item] = root;
            item          = parent;
        }

        return root;
    }

    bool connected(unsigned int item, unsigned int another_item)
    {
        return find(item) == find(another_item);
    }

private:
    vector<unsigned int> parents;
    vector<unsigned int> ranks;

    unsigned int componenets;
};

struct Edge
{
    unsigned int source;
    unsigned int destination;
    unsigned int weight;
};

bool operator>(const Edge& left, const Edge& right)
{
    return left.weight > right.weight;
}

unsigned int max_weight(vector<Edge>& edges, unsigned int nodes)
{
    UnionFind forest(nodes + 1);
    sort(edges.begin(), edges.end(), greater<Edge>());

    unsigned int weight = edges.front().weight;

    for (unsigned int i = 0, added = 0; added < nodes - 1; ++i)
    {
        if (!forest.connected(edges[i].source, edges[i].destination))
        {
            forest.link(edges[i].source, edges[i].destination);
            weight = min(weight, edges[i].weight);
            ++added;
        }
    }

    return weight;
}

int main()
{
    use_io_optimizations();

    unsigned int nodes;
    unsigned int edges_count;

    cin >> nodes >> edges_count;

    vector<Edge> edges(edges_count);

    for (unsigned int i = 0; i < edges_count; ++i)
    {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    cout << max_weight(edges, nodes) << '\n';

    return 0;
}
