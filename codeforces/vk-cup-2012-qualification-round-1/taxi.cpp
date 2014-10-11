#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int groups_count;
    cin >> groups_count;

    vector<unsigned int> groups_per_size(5, 0);

    for (unsigned int i {0}; i < groups_count; ++i)
    {
        unsigned int group_size;
        cin >> group_size;

        ++groups_per_size[group_size];
    }

    unsigned int taxis = (ceil(groups_per_size[2] / 2.0) +
                          groups_per_size[3] +
                          groups_per_size[4]);

    if (groups_per_size[1] > groups_per_size[3])
    {
        unsigned int difference {groups_per_size[1] - groups_per_size[3]};

        if (groups_per_size[2] % 2 != 0)
        {
            difference = difference > 2 ? difference - 2 : 0;
        }

        taxis += ceil(difference / 4.0);
    }

    cout << taxis << '\n';

    return 0;
}
