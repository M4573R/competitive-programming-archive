#include <iostream>
#include <sstream>
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
        ranks(items)
    {
        for (unsigned int i {0}; i < items; ++i)
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

private:
    vector<unsigned int> parents;
    vector<unsigned int> ranks;
};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int computers;
        cin >> computers;
        cin.get();

        unsigned int successful   {0};
        unsigned int unsuccessful {0};

        UnionFind network(computers + 1);

        for (string line; getline(cin, line) && !line.empty(); )
        {
            istringstream query {line};

            char operation;
            unsigned int first;
            unsigned int second;

            query >> operation >> first >> second;

            if (operation == 'c')
            {
                network.link(first, second);
            }
            else if (network.connected(first, second))
            {
                ++successful;
            }
            else
            {
                ++unsuccessful;
            }
        }

        cout << successful << ',' << unsuccessful << '\n';

        if (i < test_cases - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
