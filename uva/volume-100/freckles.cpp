#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline double length(const pair<double, double>& from,
                     const pair<double, double>& to)
{
    return sqrt(pow(from.first - to.first,   2) +
                pow(from.second - to.second, 2));
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
    vector<unsigned int> parents;
    vector<unsigned int> ranks;

    unsigned int components;
};

struct Edge
{
    unsigned int source;
    unsigned int destination;
    double weight;

    Edge(unsigned int source=0, unsigned int destination=0, double weight=0):
        source(source), destination(destination), weight(weight)
    { }
};

bool operator<(const Edge& left, const Edge& right)
{
    return left.weight < right.weight;
}

double min_ink_lines_length(vector<Edge>& edges, unsigned int nodes)
{
    UnionFind forest(nodes);

    sort(edges.begin(), edges.end());

    double       mst_weight {0};
    unsigned int mst_edges  {0};

    for (unsigned int i {0}; mst_edges < nodes - 1; ++i)
    {
        if (!forest.connected(edges[i].source, edges[i].destination))
        {
            mst_weight += edges[i].weight;
            mst_edges  += 1;

            forest.link(edges[i].source, edges[i].destination);
        }
    }

    return mst_weight;
}

constexpr unsigned int precision {2};

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(precision);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int freckles_count;
        cin >> freckles_count;

        vector<pair<double, double>> freckles(freckles_count);
        vector<Edge>                 distances;

        for (unsigned int x {0}; x < freckles_count; ++x)
        {
            cin >> freckles[x].first >> freckles[x].second;

            for (unsigned int y {0}; y < x; ++y)
            {
                distances.push_back(
                    Edge{x, y, length(freckles[x], freckles[y])}
                );
            }
        }

        cout << min_ink_lines_length(distances, freckles_count) << '\n';

        if (i < test_cases - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
