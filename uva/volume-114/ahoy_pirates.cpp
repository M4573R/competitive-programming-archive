#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr unsigned int upper_limit {1024000};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

enum class Updates
{
    None,
    ToBuccaneer,
    ToBarbary,
    Invert
};

class SegmentTree
{
public:
    SegmentTree(unsigned int size):
        size(size)
    {
        unsigned int height {0};

        while ((1 << height) < size)
        {
            ++height;
        }

        values .resize(1 << (height + 1));
        updates.resize(1 << (height + 1));
    }

    void build(const string& pirates)
    {
        size = pirates.size();
        build(1, 0, size - 1, pirates);
    }

    void update(unsigned int query_lower,
                unsigned int query_upper,
                Updates type)
    {
        update(1, 0, size - 1, query_lower, query_upper, type);
    }

    unsigned int query(unsigned int query_lower,
                       unsigned int query_upper)
    {
        return query(1, 0, size - 1, query_lower, query_upper);
    }

private:
    vector<unsigned int> values;
    vector<Updates> updates;
    unsigned int size;

    void build(unsigned int node,
               unsigned int lower,
               unsigned int upper,
               const string& pirates)
    {
        if (lower == upper)
        {
            values[node]  = pirates[lower] - '0';
            updates[node] = Updates::None;
            return;
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        build(left,  lower,      middle, pirates);
        build(right, middle + 1, upper,  pirates);

        values[node]  = values[left] + values[right];
        updates[node] = Updates::None;
    }

    void update(unsigned int node,
                unsigned int lower,
                unsigned int upper,
                unsigned int query_lower,
                unsigned int query_upper,
                Updates type)
    {
        propagate(node, lower, upper);

        if (lower > query_upper || upper < query_lower)
        {
            return;
        }

        if (lower >= query_lower && upper <= query_upper)
        {
            set_update(node, type);
            propagate(node, lower, upper);
            return;
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        update(left,  lower,      middle, query_lower, query_upper, type);
        update(right, middle + 1, upper,  query_lower, query_upper, type);

        values[node] = values[left] + values[right];
    }

    unsigned int query(unsigned int node,
                       unsigned int lower,
                       unsigned int upper,
                       unsigned int query_lower,
                       unsigned int query_upper)
    {
        if (lower > query_upper || upper < query_lower)
        {
            return 0;
        }

        propagate(node, lower, upper);

        if (lower >= query_lower && upper <= query_upper)
        {
            return values[node];
        }

        unsigned int middle {(lower + upper) / 2};

        unsigned int left   {2 * node};
        unsigned int right  {2 * node + 1};

        return (query(left,  lower,      middle, query_lower, query_upper) +
                query(right, middle + 1, upper,  query_lower, query_upper));
    }

    void propagate(unsigned int node,
                   unsigned int lower,
                   unsigned int upper)
    {
        if (updates[node] != Updates::None)
        {
            unsigned int left  {2 * node};
            unsigned int right {2 * node + 1};

            if (lower != upper)
            {
                set_update(left,  updates[node]);
                set_update(right, updates[node]);
            }

            apply_update(node, lower, upper);
        }
    }

    void set_update(unsigned int node,
                    Updates type)
    {
        if (type == Updates::ToBuccaneer)
        {
            updates[node] = type;
        }
        else if (type == Updates::ToBarbary)
        {
            updates[node] = type;
        }
        else if (type == Updates::Invert)
        {
            if (updates[node] == Updates::None)
            {
                updates[node] = Updates::Invert;
            }
            else if (updates[node] == Updates::ToBuccaneer)
            {
                updates[node] = Updates::ToBarbary;
            }
            else if (updates[node] == Updates::ToBarbary)
            {
                updates[node] = Updates::ToBuccaneer;
            }
            else
            {
                updates[node] = Updates::None;
            }
        }
    }

    void apply_update(unsigned int node,
                      unsigned int lower,
                      unsigned int upper)
    {
        if (updates[node] == Updates::ToBuccaneer)
        {
            values[node] = upper - lower + 1;
        }
        else if (updates[node] == Updates::ToBarbary)
        {
            values[node] = 0;
        }
        else if (updates[node] == Updates::Invert)
        {
            values[node] = (upper - lower + 1) - values[node];
        }

        updates[node] = Updates::None;
    }
};

string read_pirates()
{
    unsigned int lines;
    cin >> lines;

    string pirates;

    for (unsigned int i {0}; i < lines; ++i)
    {
        unsigned int times;
        cin >> times;

        string group;
        cin >> group;

        for (unsigned int j {0}; j < times; ++j)
        {
            pirates += group;
        }
    }

    return pirates;
}

int main()
{
    use_io_optimizations();

    SegmentTree tree(upper_limit);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        cout << "Case " << test << ":\n";

        tree.build(read_pirates());

        unsigned int queries;
        cin >> queries;

        for (unsigned int query {1}, i {0}; query <= queries; ++query)
        {
            char type;
            unsigned int from;
            unsigned int to;

            cin >> type >> from >> to;

            if (type == 'F')
            {
                tree.update(from, to, Updates::ToBuccaneer);
            }
            else if (type == 'E')
            {
                tree.update(from, to, Updates::ToBarbary);
            }
            else if (type == 'I')
            {
                tree.update(from, to, Updates::Invert);
            }
            else
            {
                cout << 'Q' << ++i << ": " << tree.query(from, to) << '\n';
            }
        }
    }

    return 0;
}
