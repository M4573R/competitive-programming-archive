#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
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
        for (unsigned int i = 0; i < components; ++i)
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
            parents[root_i] = root_j;
        }
        else if (ranks[root_i] > ranks[root_j])
        {
            parents[root_j] = root_i;
        }
        else
        {
            parents[root_j] = root_i;
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

    bool connected(unsigned int item, unsigned int another_item)
    {
        return find(item) == find(another_item);
    }

    unsigned int size() const
    {
        return components;
    }

private:
    std::vector<unsigned int> parents;
    std::vector<unsigned int> ranks;

    unsigned int components;
};

struct Edge
{
    unsigned int source;
    unsigned int destination;
    int weight;

    Edge(unsigned int source=0, unsigned int destination=0, int weight=0):
        source(source),
        destination(destination),
        weight(weight)
    { }
};

bool operator<(const Edge& left, const Edge& right)
{
    return left.weight < right.weight;
}

vector<Edge> kruskal(vector<Edge>& edges, unsigned int nodes)
{
    vector<Edge> mst(nodes - 1);
    UnionFind    forest(nodes);

    sort(edges.begin(), edges.end());

    unsigned int mst_edges = 0;

    for (unsigned int i = 0; mst_edges < mst.size(); ++i)
    {
        if (!forest.connected(edges[i].source, edges[i].destination))
        {
            mst[mst_edges++] = edges[i];
            forest.link(edges[i].source, edges[i].destination);
        }
    }

    return mst;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int islands_count;
        unsigned int bridges_count;

        cin >> islands_count >> bridges_count;

        vector<Edge> bridges(bridges_count);

        for (unsigned int j {0}; j < bridges_count; ++j)
        {
            cin >> bridges[j].source
                >> bridges[j].destination
                >> bridges[j].weight;

            --bridges[j].source;
            --bridges[j].destination;
        }

        for (const auto& edge : kruskal(bridges, islands_count))
        {
            cout << edge.source + 1 << ' ' << edge.destination + 1 << '\n';
        }
    }

    return 0;
}
