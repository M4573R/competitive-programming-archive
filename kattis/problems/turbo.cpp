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

    void add(unsigned int index, int value)
    {
        for (unsigned int i {index}; i < tree.size(); i += i & (-i))
        {
            tree[i] += value;
        }
    }

    int sum(unsigned int left, unsigned int right) const
    {
        return sum(right) - sum(left - 1);
    }

private:
    vector<int> tree;

    int sum(unsigned int up_to) const
    {
        int sum {0};

        for (unsigned int i {up_to}; i > 0; i -= i & (-i))
        {
            sum += tree[i];
        }

        return sum;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int elements;
    cin >> elements;

    FenwickTree swaps(elements);
    vector<unsigned int> positions(elements + 1);

    for (unsigned int i {1}; i <= elements; ++i)
    {
        unsigned int element;
        cin >> element;

        positions[element] = i;
        swaps.add(i, 1);
    }

    unsigned int minimum {1};
    unsigned int maximim {elements};

    for (unsigned int i {0}; i < elements; ++i)
    {
        if (i % 2 == 0)
        {
            swaps.add(positions[minimum], -1);
            cout << swaps.sum(1, positions[minimum++] - 1) << '\n';
        }
        else
        {
            swaps.add(positions[maximim], -1);
            cout << swaps.sum(positions[maximim--] + 1, elements) << '\n';
        }
    }

    return 0;
}
