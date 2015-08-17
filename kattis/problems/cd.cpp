#include <algorithm>
#include <iostream>
#include <iterator>
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

    unsigned int jacks;
    unsigned int jills;

    while (cin >> jacks >> jills && (jacks != 0 || jills != 0))
    {
        vector<unsigned int> jacks_cds(jacks);

        for (auto& cd : jacks_cds)
        {
            cin >> cd;
        }

        vector<unsigned int> jills_cds(jills);

        for (auto& cd : jills_cds)
        {
            cin >> cd;
        }

        vector<unsigned int> common;

        set_intersection(jacks_cds.cbegin(), jacks_cds.cend(),
                         jills_cds.cbegin(), jills_cds.cend(),
                         back_inserter(common));

        cout << common.size() << '\n';
    }

    return 0;
}
