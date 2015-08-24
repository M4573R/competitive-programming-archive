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
    unsigned int from;
    unsigned int to;

    unsigned int value;
    bool updates;

    Node():
        value(0),
        updates(false)
    { }

    void add_update()
    {
        updates = !updates;
    }

    void apply_updates()
    {
        value   = (to - from + 1) - value;
        updates = false;
    }

    void merge(const Node& left, const Node& right)
    {
        value = left.value + right.value;

        if (left.is_lazy())
        {
            value += (left.to - left.from + 1) - 2 * left.value;
        }

        if (right.is_lazy())
        {
            value += (right.to - right.from + 1) - 2 * right.value;
        }
    }

    unsigned int get() const
    {
        return value;
    }

    bool is_lazy() const
    {
        return updates;
    }

    bool is_leaf() const
    {
        return from == to;
    }
};

class SegmentTree
{
public:
    SegmentTree(unsigned int size)
    {
        unsigned int height {0};

        while ((1 << height) < size)
        {
            ++height;
        }

        tree.resize(1 << (height + 1));
        build(1, 0, size - 1);
    }

    void update(unsigned int query_lower, unsigned int query_upper)
    {
        update(1, query_lower, query_upper);
    }

    unsigned int query(unsigned int query_lower, unsigned int query_upper)
    {
        return query(1, query_lower, query_upper).get();
    }

private:
    vector<Node> tree;

    void build(unsigned int node,
               unsigned int lower,
               unsigned int upper)
    {
        tree[node].from = lower;
        tree[node].to   = upper;

        if (lower == upper)
        {
            return;
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        build(left,  lower,      middle);
        build(right, middle + 1, upper);
    }

    void update(unsigned int node,
                unsigned int query_lower,
                unsigned int query_upper)
    {
        if (tree[node].from >= query_lower && tree[node].to <= query_upper)
        {
            tree[node].add_update();
            return;
        }

        unsigned int middle {(tree[node].from + tree[node].to) / 2};

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        if (query_lower > middle)
        {
            update(right, query_lower, query_upper);
        }
        else if (query_upper <= middle)
        {
            update(left, query_lower, query_upper);
        }
        else
        {
            update(left,  query_lower, query_upper);
            update(right, query_lower, query_upper);
        }

        tree[node].merge(tree[left], tree[right]);
    }

    Node query(unsigned int node,
               unsigned int query_lower,
               unsigned int query_upper)
    {
        if (tree[node].is_lazy())
        {
            propagate(node);
        }

        if (tree[node].from >= query_lower && tree[node].to <= query_upper)
        {
            return tree[node];
        }

        unsigned int middle {(tree[node].from + tree[node].to) / 2};

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        if (query_lower > middle)
        {
            return query(right, query_lower, query_upper);
        }

        if (query_upper <= middle)
        {
            return query(left, query_lower, query_upper);
        }

        Node result;
        result.merge(query(left,  query_lower, query_upper),
                     query(right, query_lower, query_upper));

        return result;
    }

    void propagate(unsigned int node)
    {
        if (!tree[node].is_leaf())
        {
            unsigned int left  {2 * node};
            unsigned int right {2 * node + 1};

            tree[left ].add_update();
            tree[right].add_update();
        }

        tree[node].apply_updates();
    }
};

int main()
{
    use_io_optimizations();

    unsigned int coins;
    unsigned int queries;

    cin >> coins >> queries;

    SegmentTree tree(coins);

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int type;
        unsigned int from;
        unsigned int to;

        cin >> type >> from >> to;

        if (type == 0)
        {
            tree.update(from, to);
        }
        else
        {
            cout << tree.query(from, to) << '\n';
        }
    }

    return 0;
}
