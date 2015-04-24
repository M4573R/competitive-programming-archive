#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class FenwickTree
{
public:
    FenwickTree(unsigned int size):
        tree(size + 1)
    { }

    unsigned int query(unsigned int index) const
    {
        unsigned int sum {0};

        for (unsigned int i {index}; i > 0; i -= i & (-i))
        {
            sum += tree[i];
        }

        return sum;
    }

    void update(unsigned int from, unsigned int to, unsigned int value)
    {
        update(from, value);
        update(to + 1, -value);
    }

    void update(unsigned int index, unsigned int value)
    {
        for (unsigned int i {index}; i < tree.size(); i += i & (-i))
        {
            tree[i] += value;
        }
    }

private:
    vector<unsigned int> tree;
};

int main()
{
    use_io_optimizations();

    unsigned int knights;
    cin >> knights;

    FenwickTree tree(knights);

    for (unsigned int i {0}; i <= knights; ++i)
    {
        unsigned int from;
        unsigned int to;
        unsigned int coins;

        cin >> from >> to >> coins;

        tree.update(from, to, coins);
    }

    for (unsigned int i {1}; i <= knights; ++i)
    {
        cout << tree.query(i) << (i < knights ? ' ' : '\n');
    }

    return 0;
}
