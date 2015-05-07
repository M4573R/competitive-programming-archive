#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    // * using both lines gives RTE on LightOJ
    // * using only the first line gives TLE on LightOJ

    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class SparseTable
{
public:
    SparseTable(const vector<unsigned int>& sequence)
    {
        unsigned int height = 0;

        while ((1 << (height + 1)) <= sequence.size())
        {
            ++height;
        }

        table = vector< vector<unsigned int> >(
            sequence.size(), vector<unsigned int>(height + 1)
        );

        build(sequence);
    }

    unsigned int query(unsigned int from, unsigned int to) const
    {
        unsigned int height = 0;

        while ((1 << (height + 1)) <= to - from + 1)
        {
            ++height;
        }

        return min(table[from][height], table[to - (1 << height) + 1][height]);
    }

private:
    vector< vector<unsigned int> > table;

    void build(const vector<unsigned int>& sequence)
    {
        for (unsigned int i = 0; i < table.size(); ++i)
        {
            table[i][0] = sequence[i];
        }

        for (unsigned int j = 1; (1 << j) <= table.size(); ++j)
        {
            for (unsigned int i = 0; i + (1 << j) <= table.size(); ++i)
            {
                table[i][j] = min(table[i][j - 1],
                                  table[i + (1 << (j - 1))][j - 1]);
            }
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
        unsigned int length;
        unsigned int queries;

        cin >> length >> queries;

        vector<unsigned int> sequence(length);

        for (unsigned int i = 0; i < length; ++i)
        {
            cin >> sequence[i];
        }

        SparseTable table(sequence);

        cout << "Case " << test << ":\n";

        for (unsigned int i = 0; i < queries; ++i)
        {
            unsigned int from;
            unsigned int to;

            cin >> from >> to;

            cout << table.query(from - 1, to - 1) << '\n';
        }
    }

    return 0;
}
