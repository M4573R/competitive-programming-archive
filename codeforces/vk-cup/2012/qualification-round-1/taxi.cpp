#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int groups_count;
    cin >> groups_count;

    vector<unsigned int> groups_per_size(5);

    for (unsigned int i {0}; i < groups_count; ++i)
    {
        unsigned int group_size;
        cin >> group_size;

        ++groups_per_size[group_size];
    }

    unsigned int taxis {
        groups_per_size[2] / 2 + groups_per_size[3] + groups_per_size[4]
    };

    groups_per_size[1] -= min(groups_per_size[1], groups_per_size[3]);
    groups_per_size[2] %= 2;

    taxis += (2 * groups_per_size[2] + groups_per_size[1] + 3) / 4;

    cout << taxis << '\n';

    return 0;
}
