#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

using namespace std;

const unsigned int infinity = numeric_limits<unsigned int>::max();

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
        ranks(items),
        parents(items),
        components(items)
    {
        for (unsigned int i = 0; i < components; ++i)
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

        --components;
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

    unsigned int size() const
    {
        return components;
    }

private:
    vector<unsigned int> ranks;
    vector<unsigned int> parents;

    unsigned int components;
};

struct Edge
{
    unsigned int from;
    unsigned int to;
    unsigned int cost;
};


bool operator<(const Edge& left, const Edge& right)
{
    return left.cost < right.cost;
}

unsigned int min_cost(vector<Edge>& edges, unsigned int nodes)
{
    unsigned int cost     = 0;
    unsigned int mst_size = 0;

    UnionFind tree(nodes);

    sort(edges.begin(), edges.end());

    for (unsigned int i = 0; i < edges.size(); ++i)
    {
        if (!tree.connected(edges[i].from, edges[i].to))
        {
            ++mst_size;
            cost += edges[i].cost;
            tree.link(edges[i].from, edges[i].to);
        }
    }

    return mst_size == nodes - 1 ? cost : infinity;
}

void read_input(unsigned int& nodes, vector<Edge>& edges)
{
    unsigned int edges_count;
    cin >> edges_count;

    edges.resize(edges_count);

    unsigned int id = 0;
    map<string, unsigned int> ids;

    for (unsigned int i = 0; i < edges_count; ++i)
    {
        string from;
        string to;
        unsigned int cost;

        cin >> from >> to >> cost;

        if (!ids.count(from))
        {
            ids[from] = id++;
        }

        if (!ids.count(to))
        {
            ids[to] = id++;
        }

        edges[i].from = ids[from];
        edges[i].to   = ids[to];
        edges[i].cost = cost;
    }

    nodes = ids.size();
}

void write_output(unsigned int test, unsigned int cost)
{
    cout << "Case " << test << ": ";

    if (cost == infinity)
    {
        cout << "Impossible";
    }
    else
    {
        cout << cost;
    }

    cout << '\n';
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int nodes;
        vector<Edge> edges;

        read_input(nodes, edges);
        write_output(test, min_cost(edges, nodes));
    }

    return 0;
}
