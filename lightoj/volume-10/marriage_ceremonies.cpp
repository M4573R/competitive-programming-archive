#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class MaxPriority
{
public:
    MaxPriority(const vector< vector<unsigned int> >& priorities):
        couples(priorities.size()),
        priorities(priorities),
        subtasks(couples, vector<unsigned int>(1 << couples, -1))
    { }

    unsigned int find()
    {
        return find(0, 0);
    }

private:
    unsigned int couples;

    vector< vector<unsigned int> > priorities;
    vector< vector<unsigned int> > subtasks;

    unsigned int find(unsigned int i, unsigned int mask)
    {
        if (i == couples)
        {
            return 0;
        }

        if (subtasks[i][mask] != -1)
        {
            return subtasks[i][mask];
        }

        unsigned int max_priority = 0;

        for (unsigned int j = 0; j < couples; ++j)
        {
            if (!(mask & (1 << j)))
            {
                max_priority = max(
                    max_priority,
                    find(i + 1, mask | (1 << j)) + priorities[i][j]
                );
            }
        }

        return subtasks[i][mask] = max_priority;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int couples;
        cin >> couples;

        vector< vector<unsigned int> > priorities(
            couples, vector<unsigned int>(couples)
        );

        for (unsigned int i = 0; i < couples; ++i)
        {
            for (unsigned int j = 0; j < couples; ++j)
            {
                cin >> priorities[i][j];
            }
        }

        cout << "Case " << test << ": " << MaxPriority(priorities).find() << '\n';
    }

    return 0;
}
