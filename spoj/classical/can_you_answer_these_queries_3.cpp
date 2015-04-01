#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Node
{
    int maximum;
    int prefix;
    int suffix;
    int total;

    void assign(int value)
    {
        maximum = value;
        prefix  = value;
        suffix  = value;
        total   = value;
    }

    void merge(const Node& left, const Node& right)
    {
        maximum = max(max(left.maximum, right.maximum),
                      left.suffix + right.prefix);

        prefix  = max(left.prefix,  left.total  + right.prefix);
        suffix  = max(right.suffix, left.suffix + right.total);

        total   = left.total + right.total;
    }

    int get() const
    {
        return maximum;
    }
};

class SegmentTree
{
public:
    SegmentTree(const vector<int>& item):
        size(item.size())
    {
        unsigned int height {0};

        while ((1 << height) < size)
        {
            ++height;
        }

        tree.resize(1 << (height + 1));
        build(item, 1, 0, size - 1);
    }

    int query(unsigned int query_lower, unsigned int query_upper) const
    {
        return query(1, 0, size - 1, query_lower, query_upper).get();
    }

    void update(unsigned int index, int value)
    {
        update(1, 0, size - 1, index, value);
    }

private:
    vector<Node> tree;
    unsigned int size;

    void build(const vector<int>& items,
               unsigned int node,
               unsigned int lower,
               unsigned int upper)
    {
        if (lower == upper)
        {
            tree[node].assign(items[lower]);
            return;
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {left_child (node)};
        unsigned int right  {right_child(node)};

        build(items, left,  lower,      middle);
        build(items, right, middle + 1, upper);

        tree[node].merge(tree[left], tree[right]);
    }

    Node query(unsigned int node,
               unsigned int lower,
               unsigned int upper,
               unsigned int query_lower,
               unsigned int query_upper) const
    {
        if (lower >= query_lower && upper <= query_upper)
        {
            return tree[node];
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {left_child (node)};
        unsigned int right  {right_child(node)};

        if (query_lower > middle)
        {
            return query(right, middle + 1, upper, query_lower, query_upper);
        }

        if (query_upper <= middle)
        {
            return query(left, lower, middle, query_lower, query_upper);
        }

        Node result;
        result.merge(query(left,  lower,      middle, query_lower, query_upper),
                     query(right, middle + 1, upper,  query_lower, query_upper));

        return result;
    }

    void update(unsigned int node,
                unsigned int lower,
                unsigned int upper,
                unsigned int index,
                int value)
    {
        if (lower == upper)
        {
            tree[node].assign(value);
            return;
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {left_child (node)};
        unsigned int right  {right_child(node)};

        if (index <= middle)
        {
            update(left, lower, middle, index, value);
        }
        else
        {
            update(right, middle + 1, upper, index, value);
        }

        tree[node].merge(tree[left], tree[right]);
    }

    unsigned int left_child(unsigned int node) const
    {
        return 2 * node;
    }

    unsigned int right_child(unsigned int node) const
    {
        return 2 * node + 1;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int length;
    cin >> length;

    vector<int> sequence(length);

    for (auto& element : sequence)
    {
        cin >> element;
    }

    SegmentTree tree(sequence);

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int type;
        cin >> type;

        if (type == 0)
        {
            unsigned int index;
            int value;

            cin >> index >> value;

            tree.update(index - 1, value);
        }
        else
        {
            unsigned int lower;
            unsigned int upper;

            cin >> lower >> upper;

            cout << tree.query(lower - 1, upper - 1) << '\n';
        }
    }

    return 0;
}
