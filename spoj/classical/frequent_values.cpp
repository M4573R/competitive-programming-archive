#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef vector< pair<unsigned int, unsigned int> > Query;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Node
{
    unsigned int max_frequency;
    unsigned int leftmost_frequency;
    unsigned int rightmost_frequency;

    Node(unsigned int max_frequency       = 0,
         unsigned int leftmost_frequency  = 0,
         unsigned int rightmost_frequency = 0):
        max_frequency(max_frequency),
        leftmost_frequency(leftmost_frequency),
        rightmost_frequency(rightmost_frequency)
    { }
};

class SegmentTree
{
public:
    SegmentTree(const vector<int>& array):
        items(array),
        tree(2 * pow(2.0, ceil(log2(array.size()))))
    {
        initialize(1, 0, items.size() - 1);
    }

    unsigned int get(unsigned int query_left, unsigned int query_right)
    {
        return get(1, 0, items.size() - 1, query_left, query_right);
    }

private:
    vector<int> items;
    vector<Node> tree;

    void initialize(unsigned int node, unsigned int left, unsigned int right)
    {
        if (left == right)
        {
            tree[node] = Node(1, 1, 1);
        }
        else
        {
            unsigned int middle = (left + right) / 2;

            unsigned int left_child  = 2 * node;
            unsigned int right_child = left_child + 1;

            initialize(2 * node, left, middle);
            initialize(2 * node + 1, middle + 1, right);

            merge(tree[node], tree[left_child], tree[right_child], left, right);
        }
    }

    void merge(Node& parent,
               Node& left_child,
               Node& right_child,
               unsigned int left,
               unsigned int right)
    {
        parent.max_frequency       = max(left_child.max_frequency,
                                         right_child.max_frequency);

        parent.leftmost_frequency  = left_child.leftmost_frequency;
        parent.rightmost_frequency = right_child.rightmost_frequency;

        unsigned int middle = (left + right) / 2;

        if (items[left] == items[middle + 1])
        {
            parent.leftmost_frequency += right_child.leftmost_frequency;
        }

        if (items[middle] == items[right])
        {
            parent.rightmost_frequency += left_child.rightmost_frequency;
        }

        if (items[middle] == items[middle + 1])
        {
            parent.max_frequency = max(parent.max_frequency,
                                       left_child.rightmost_frequency +
                                       right_child.leftmost_frequency);
        }
    }

    unsigned int get(unsigned int node,
                     unsigned int left,
                     unsigned int right,
                     unsigned int query_left,
                     unsigned int query_right)
    {
        if (left >= query_left && right <= query_right)
        {
            return tree[node].max_frequency;
        }

        unsigned int middle = (left + right) / 2;

        unsigned int left_child  = 2 * node;
        unsigned int right_child = left_child + 1;

        if (query_right <= middle)
        {
            return get(left_child, left, middle, query_left, query_right);
        }

        if (query_left > middle)
        {
            return get(right_child, middle + 1, right, query_left, query_right);
        }

        unsigned int left_frequency  = get(2 * node,
                                           left,
                                           middle,
                                           query_left,
                                           query_right);

        unsigned int right_frequency = get(2 * node + 1,
                                           middle + 1,
                                           right,
                                           query_left,
                                           query_right);

        unsigned int max_frequency = max(left_frequency, right_frequency);

        if (items[middle] == items[middle + 1])
        {
            max_frequency = max(max_frequency,
                                (min(tree[left_child].rightmost_frequency,
                                     middle - query_left + 1) +
                                 min(tree[right_child].leftmost_frequency,
                                     query_right - middle)));
        }

        return max_frequency;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int sequence_length;
    unsigned int queries_count;

    while ((cin >> sequence_length >> queries_count) && (sequence_length != 0))
    {
        vector<int> sequence(sequence_length);

        for (unsigned int i = 0; i < sequence_length; ++i)
        {
            cin >> sequence[i];
        }

        SegmentTree tree(sequence);

        for (unsigned int i = 0; i < queries_count; ++i)
        {
            unsigned int left;
            unsigned int right;

            cin >> left >> right;

            cout << tree.get(left - 1, right - 1) << '\n';
        }
    }

    return 0;
}
