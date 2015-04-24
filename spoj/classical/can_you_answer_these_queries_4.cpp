#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class SegmentTree
{
public:
    SegmentTree(const vector<unsigned long long>& sequence):
        size(sequence.size())
    {
        unsigned int height {0};

        while ((1 << height) < size)
        {
            ++height;
        }

        tree.resize(1 << (height + 1));
        build(1, 0, size - 1, sequence);
    }

    unsigned long long query(unsigned int query_lower,
                             unsigned int query_upper) const
    {
        return query(1, 0, size - 1, query_lower, query_upper);
    }

    void update(unsigned int query_lower, unsigned int query_upper)
    {
        update(1, 0, size - 1, query_lower, query_upper);
    }

private:
    vector<unsigned long long> tree;
    unsigned int size;

    void build(unsigned int node,
               unsigned int lower,
               unsigned int upper,
               const vector<unsigned long long>& sequence)
    {
        if (lower == upper)
        {
            tree[node] = sequence[lower];
            return;
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        build(left,  lower,      middle, sequence);
        build(right, middle + 1, upper,  sequence);

        tree[node] = tree[left] + tree[right];
    }

    unsigned long long query(unsigned int node,
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

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        if (query_lower > middle)
        {
            return query(right, middle + 1, upper, query_lower, query_upper);
        }

        if (query_upper <= middle)
        {
            return query(left, lower, middle, query_lower, query_upper);
        }

        return (query(left,  lower,      middle, query_lower, query_upper) +
                query(right, middle + 1, upper,  query_lower, query_upper));
    }

    void update(unsigned int node,
                unsigned int lower,
                unsigned int upper,
                unsigned int query_lower,
                unsigned int query_upper)
    {
        if (tree[node] <= upper - lower + 1)
        {
            return;
        }

        if (lower == upper)
        {
            tree[node] = sqrt(tree[node]);
            return;
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        if (query_lower > middle)
        {
            update(right, middle + 1, upper, query_lower, query_upper);
        }
        else if (query_upper <= middle)
        {
            update(left, lower, middle, query_lower, query_upper);
        }
        else
        {
            update(left,  lower,      middle, query_lower, query_upper);
            update(right, middle + 1, upper,  query_lower, query_upper);
        }

        tree[node] = tree[left] + tree[right];
    }
};

int main()
{
    use_io_optimizations();

    for (unsigned int length, test {1}; cin >> length; ++test)
    {
        cout << "Case #" << test << ":\n";

        vector<unsigned long long> sequence(length);

        for (auto& element : sequence)
        {
            cin >> element;
        }

        SegmentTree tree(sequence);

        unsigned int operations;
        cin >> operations;

        for (unsigned int i {0}; i < operations; ++i)
        {
            unsigned int type;
            unsigned int from;
            unsigned int to;

            cin >> type >> from >> to;

            if (from > to)
            {
                swap(from, to);
            }

            if (type == 0)
            {
                tree.update(from - 1, to - 1);
            }
            else
            {
                cout << tree.query(from - 1, to - 1) << '\n';
            }
        }

        cout << '\n';
    }

    return 0;
}
