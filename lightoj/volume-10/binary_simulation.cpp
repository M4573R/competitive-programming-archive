#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    // * using both lines gives RTE on LightOJ
    // * using only the first gives TLE

    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class FenwickTree
{
public:
    FenwickTree(const string& sequence):
        tree(sequence.size() + 1)
    {
        for (unsigned int i = 0; i < sequence.size(); ++i)
        {
            if (sequence[i] == '1')
            {
                update(i + 1, i + 1);
            }
        }
    }

    void update(unsigned int from, unsigned int to)
    {
        update(from, 1);
        update(to + 1, -1);
    }

    bool query(unsigned int index)
    {
        int sum = 0;

        for (unsigned int i = index; i > 0; i -= i & (-i))
        {
            sum += tree[i];
        }

        return sum % 2;
    }

private:
    vector<int> tree;

    void update(unsigned int index, int value)
    {
        for (unsigned int i = index; i < tree.size(); i += i & (-i))
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

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        string binary;
        cin >> binary;

        unsigned int queries;
        cin >> queries;

        cout << "Case " << test << ":\n";

        FenwickTree tree(binary);

        for (unsigned int i = 0; i < queries; ++i)
        {
            char type;
            cin >> type;

            if (type == 'I')
            {
                unsigned int from;
                unsigned int to;

                cin >> from >> to;

                tree.update(from, to);
            }
            else
            {
                unsigned int index;
                cin >> index;

                cout << tree.query(index) << '\n';
            }
        }
    }

    return 0;
}
