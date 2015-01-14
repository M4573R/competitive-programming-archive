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

struct Line
{
    unsigned int source;
    unsigned int destination;
    unsigned int length;
};

bool operator<(const Line& left, const Line& right)
{
    return left.length < right.length;
}

unsigned int min_cable_length(vector<Line>& measurements, unsigned int chairs)
{
    UnionFind forest(chairs + 1);

    sort(measurements.begin(), measurements.end());

    unsigned int cable_length = 0;
    unsigned int cable_lines  = 0;

    for (vector<Line>::size_type i {0}; cable_lines < chairs - 1; ++i)
    {
        if (!forest.connected(measurements[i].source,
                              measurements[i].destination))
        {
            cable_length += measurements[i].length;
            cable_lines  += 1;

            forest.link(measurements[i].source, measurements[i].destination);
        }
    }

    return cable_length;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int chairs;
        unsigned int measurements_count;

        cin >> chairs >> measurements_count;

        vector<Line> measurements(measurements_count);

        for (unsigned int i {0}; i < measurements_count; ++i)
        {
            cin >> measurements[i].source
                >> measurements[i].destination
                >> measurements[i].length;
        }

        cout << min_cable_length(measurements, chairs) << '\n';
    }

    return 0;
}
