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

vector<unsigned int> kruskal(vector<Edge>& edges, unsigned int nodes)
{
    vector<unsigned int> outside_mst_weights;
    UnionFind            forest(nodes);

    sort(edges.begin(), edges.end());

    for (vector<Edge>::size_type i {0}; i < edges.size(); ++i)
    {
        if (forest.connected(edges[i].source, edges[i].destination))
        {
            outside_mst_weights.push_back(edges[i].weight);
        }
        else
        {
            forest.link(edges[i].source, edges[i].destination);
        }
    }

    return outside_mst_weights;
}

int main()
{
    use_io_optimizations();

    unsigned int nodes_count;
    unsigned int edges_count;


    while (cin >> nodes_count >> edges_count &&
           !(nodes_count == 0 && edges_count == 0))
    {
        vector<Edge> edges(edges_count);

        for (unsigned int i {0}; i < edges_count; ++i)
        {
            cin >> edges[i].source
                >> edges[i].destination
                >> edges[i].weight;
        }

        vector<unsigned int> unused_weights {kruskal(edges, nodes_count)};

        if (unused_weights.empty())
        {
            cout << "forest";
        }
        else
        {
            for (auto weight = unused_weights.cbegin();
                 weight != unused_weights.cend();
                 ++weight)
            {
                cout << *weight;

                if (weight < unused_weights.cend() - 1)
                {
                    cout << ' ';
                }
            }
        }

        cout << '\n';
    }

    return 0;
}
