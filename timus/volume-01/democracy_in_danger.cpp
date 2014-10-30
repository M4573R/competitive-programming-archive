#include <algorithm>
#include <iostream>

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

    vector<unsigned int> groups_voters(groups_count);

    for (unsigned int& voters : groups_voters)
    {
        cin >> voters;
    }

    sort(groups_voters.begin(), groups_voters.end());

    unsigned int needed_supporters {0};
    unsigned int needed_groups     {(groups_count + 1) / 2};

    for (unsigned int i {0}; i < needed_groups; ++i)
    {
        needed_supporters += (groups_voters[i] + 1) / 2;
    }

    cout << needed_supporters;

    return 0;
}
