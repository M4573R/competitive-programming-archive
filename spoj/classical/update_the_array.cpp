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

    void update(unsigned int from, unsigned int to, int value)
    {
        update(from, value);
        update(to + 1, -value);
    }

    int query(unsigned int index)
    {
        int sum {0};

        for (unsigned int i {index}; i > 0; i -= i & (-i))
        {
            sum += tree[i];
        }

        return sum;
    }

private:
    vector<int> tree;

    void update(unsigned int index, int value)
    {
        for (unsigned int i {index}; i < tree.size(); i += i & (-i))
        {
            tree[i] += value;
        }
    }
};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int length;
        unsigned int updates;

        cin >> length >> updates;

        FenwickTree tree(length);

        for (unsigned int i {0}; i < updates; ++i)
        {
            unsigned int from;
            unsigned int to;
            int value;

            cin >> from >> to >> value;

            tree.update(from + 1, to + 1, value);
        }

        unsigned int queries;
        cin >> queries;

        for (unsigned int i {0}; i < queries; ++i)
        {
            unsigned int index;
            cin >> index;

            cout << tree.query(index + 1) << '\n';
        }
    }

    return 0;
}
