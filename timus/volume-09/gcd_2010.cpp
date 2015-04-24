#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int gcd(unsigned int left, unsigned int right)
{
    while (right)
    {
        left %= right;
        swap(left, right);
    }

    return left;
}

class SegmentTree
{
public:
    SegmentTree(unsigned int size):
        size(size)
    {
        unsigned int height {0};

        while ((1 << height) < size)
        {
            ++height;
        }

        tree.resize(1 << (height + 1));
    }

    unsigned int query() const
    {
        return max(1u, tree[1]);
    }

    void update(unsigned int index, unsigned int value)
    {
        update(1, 0, size - 1, index, value);
    }

private:
    vector<unsigned int> tree;
    unsigned int size;

    void update(unsigned int node,
                unsigned int lower,
                unsigned int upper,
                unsigned int index,
                unsigned int value)
    {
        if (lower == upper)
        {
            tree[node] = value;
            return;
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        if (index <= middle)
        {
            update(left, lower, middle, index, value);
        }
        else
        {
            update(right, middle + 1, upper, index, value);
        }

        tree[node] = gcd(tree[left], tree[right]);
    }
};

int main()
{
    use_io_optimizations();

    unsigned int operations;
    cin >> operations;

    SegmentTree tree(operations);

    multimap<unsigned int, unsigned int> indices;

    for (unsigned int i {0}; i < operations; ++i)
    {
        char type;
        unsigned int number;

        cin >> type >> number;

        if (type == '+')
        {
            tree.update(i, number);
            indices.insert(make_pair(number, i));
        }
        else
        {
            tree.update(indices.find(number)->second, 0);
            indices.erase(indices.find(number));
        }

        cout << tree.query() << '\n';
    }

    return 0;
}
