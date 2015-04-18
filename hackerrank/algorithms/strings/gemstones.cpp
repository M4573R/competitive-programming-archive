#include <algorithm>
#include <iostream>
#include <set>
#include <string>
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

    unsigned int rocks;
    cin >> rocks;

    vector<unsigned int> occurances(26);

    for (unsigned int i {0}; i < rocks; ++i)
    {
        string composition;
        cin >> composition;

        for (auto element : set<char>(composition.cbegin(), composition.cend()))
        {
            ++occurances[element - 'a'];
        }
    }

    cout << count(occurances.cbegin(), occurances.cend(), rocks) << '\n';

    return 0;
}
