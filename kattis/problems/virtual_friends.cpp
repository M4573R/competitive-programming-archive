#include <iostream>
#include <unordered_map>
#include <string>
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
        ranks(items, 1)
    {
        for (unsigned int i {0}; i < items; ++i)
        {
            parents[i] = i;
        }
    }

    void link(unsigned int left, unsigned int right)
    {
        unsigned int root_i {find(left)};
        unsigned int root_j {find(right)};

        if (root_i == root_j)
        {
            return;
        }

        if (ranks[root_i] < ranks[root_j])
        {
            parents[root_i] = root_j;
            ranks[root_j] += ranks[root_i];
        }
        else
        {
            parents[root_j] = root_i;
            ranks[root_i] += ranks[root_j];
        }
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

    unsigned int size(unsigned int item)
    {
        return ranks[find(item)];
    }

private:
    vector<unsigned int> parents;
    vector<unsigned int> ranks;
};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int friendships;
        cin >> friendships;

        UnionFind networks(100000);
        unordered_map<string, unsigned int> ids;

        for (unsigned int i {0}; i < friendships; ++i)
        {
            string first;
            string second;

            cin >> first >> second;

            if (!ids.count(first))
            {
                ids[first] = ids.size();
            }

            if (!ids.count(second))
            {
                ids[second] = ids.size();
            }

            networks.link(ids[first], ids[second]);

            cout << networks.size(ids[first]) << '\n';
        }
    }

    return 0;
}
