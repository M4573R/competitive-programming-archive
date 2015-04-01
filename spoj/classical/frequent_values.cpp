#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Node
{
    int left_value;
    int right_value;

    unsigned int max_frequency;
    unsigned int left_frequency;
    unsigned int right_frequency;

    void assign(int value)
    {
        left_value  = value;
        right_value = value;

        max_frequency   = 1;
        left_frequency  = 1;
        right_frequency = 1;
    }

    void merge(const Node& left, const Node& right)
    {
        max_frequency = max(left.max_frequency, right.max_frequency);

        if (left.right_value == right.left_value)
        {
            max_frequency = max(max_frequency,
                                left.right_frequency + right.left_frequency);
        }

        left_value      = left.left_value;
        left_frequency  = left.left_frequency;

        right_value     = right.right_value;
        right_frequency = right.right_frequency;

        if (left.left_value == right.left_value)
        {
            left_frequency += right.left_frequency;
        }

        if (left.right_value == right.right_value)
        {
            right_frequency += left.right_frequency;
        }
    }

    int get() const
    {
        return max_frequency;
    }
};

class SegmentTree
{
public:
    SegmentTree(const vector<int>& items):
        size(items.size())
    {
        unsigned int height {0};

        while ((1 << height) < size)
        {
            ++height;
        }

        tree.resize(1 << (height + 1));
        build(items, 1, 0, size - 1);
    }

    int query(unsigned int query_lower, unsigned int query_upper) const
    {
        return query(1, 0, size - 1, query_lower, query_upper).get();
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

    for (unsigned int length; cin >> length && length != 0; )
    {
        unsigned int queries;
        cin >> queries;

        vector<int> sequence(length);

        for (unsigned int i = 0; i < length; ++i)
        {
            cin >> sequence[i];
        }

        SegmentTree tree(sequence);

        for (unsigned int i {0}; i < queries; ++i)
        {
            unsigned int lower;
            unsigned int upper;

            cin >> lower >> upper;

            cout << tree.query(lower - 1, upper - 1) << '\n';
        }
    }

    return 0;
}
