#include <iostream>
#include <set>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_levels(set<unsigned int>& passed)
{
    unsigned int levels;
    cin >> levels;

    for (unsigned int i {0}; i < levels; ++i)
    {
        unsigned int level;
        cin >> level;

        passed.insert(level);
    }
}

int main()
{
    use_io_optimizations();

    unsigned int levels;
    cin >> levels;

    set<unsigned int> passed;

    read_levels(passed);
    read_levels(passed);

    if (passed.size() == levels)
    {
        cout << "I become the guy.";
    }
    else
    {
        cout << "Oh, my keyboard!";
    }

    cout << '\n';

    return 0;
}
