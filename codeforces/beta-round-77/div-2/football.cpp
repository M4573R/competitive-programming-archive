#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string players;
    cin >> players;

    unsigned int max_group {1};

    for (auto i = players.cbegin(); i != players.cend(); ++i)
    {
        unsigned int current_group {1};

        for (; i + 1 < players.cend() && *i == *(i + 1); ++i)
        {
            ++current_group;
        }

        max_group = max(max_group, current_group);
    }

    cout << (max_group >= 7 ? "YES" : "NO") << '\n';

    return 0;
}
