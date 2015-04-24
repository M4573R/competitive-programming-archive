#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int max_coordinate {32000};

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

    unsigned int query(unsigned int index) const
    {
        unsigned int sum {0};

        for (unsigned int i {index}; i > 0; i -= i & (-i))
        {
            sum += tree[i];
        }

        return sum;
    }

    void update(unsigned int index)
    {
        for (unsigned int i {index}; i < tree.size(); i += i & (-i))
        {
            ++tree[i];
        }
    }

private:
    vector<unsigned int> tree;
};

int main()
{
    use_io_optimizations();

    unsigned int stars;
    cin >> stars;

    FenwickTree tree(max_coordinate + 1);
    vector<unsigned int> level_frequencies(stars);

    for (unsigned int i {0}; i < stars; ++i)
    {
        unsigned int x;
        unsigned int y;

        cin >> x >> y;

        ++level_frequencies[tree.query(x + 1)];
        tree.update(x + 1);
    }

    for (auto frequency : level_frequencies)
    {
        cout << frequency << '\n';
    }

    return 0;
}
