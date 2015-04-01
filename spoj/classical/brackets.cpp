#include <algorithm>
#include <iostream>
#include <string>
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
    unsigned int unmatched_left;
    unsigned int unmatched_right;

    void assign(char bracket)
    {
        if (bracket == '(')
        {
            unmatched_left  = 1;
            unmatched_right = 0;
        }
        else
        {
            unmatched_left  = 0;
            unmatched_right = 1;
        }
    }

    void merge(const Node& left, const Node& right)
    {
        unsigned int matches {min(left.unmatched_left, right.unmatched_right)};

        unmatched_left  = left.unmatched_left  + right.unmatched_left  - matches;
        unmatched_right = left.unmatched_right + right.unmatched_right - matches;
    }

    bool get() const
    {
        return unmatched_left == 0 && unmatched_right == 0;
    }
};

class SegmentTree
{
public:
    SegmentTree(const string& items):
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

    void update(unsigned int index, int value)
    {
        update(1, 0, size - 1, index, value);
    }

private:
    vector<Node> tree;
    unsigned int size;

    void build(const string& items,
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

    for (unsigned int test {1}; test <= 10; ++test)
    {
        cout << "Test " << test << ":\n";

        unsigned int length;
        cin >> length;

        string brackets;
        cin >> brackets;

        SegmentTree tree(brackets);

        unsigned int queries;
        cin >> queries;

        for (unsigned int i {0}; i < queries; ++i)
        {
            unsigned int index;
            cin >> index;

            if (index == 0)
            {
                cout << (tree.query(0, length - 1) ? "YES" : "NO") << '\n';
            }
            else
            {
                --index;
                brackets[index] = (brackets[index] == '(' ? ')' : '(');
                tree.update(index, brackets[index]);
            }
        }
    }

    return 0;
}
