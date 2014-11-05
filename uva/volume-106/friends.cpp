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
        parents(items, 0),
        ranks(items, 1),
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
            ranks[root_j]  += ranks[root_i];
        }
        else
        {
            parents[root_j] = root_i;
            ranks[root_i]  += ranks[root_j];
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

    unsigned int component_size(unsigned int item)
    {
        return ranks[find(item)];
    }

private:
    vector<unsigned int> parents;
    vector<unsigned int> ranks;

    unsigned int components;
};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int citizens;
        unsigned int friend_pairs;

        cin >> citizens >> friend_pairs;

        UnionFind groups(citizens + 1);

        for (unsigned int j {0}; j < friend_pairs; ++j)
        {
            unsigned int citizen_a;
            unsigned int citizen_b;

            cin >> citizen_a >> citizen_b;

            groups.link(citizen_a, citizen_b);
        }

        unsigned int largest_group_size {0};

        for (unsigned int j {0}; j < citizens; ++j)
        {
            largest_group_size = max(largest_group_size,
                                     groups.component_size(j));
        }

        cout << largest_group_size << '\n';
    }

    return 0;
}
