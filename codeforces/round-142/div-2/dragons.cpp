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

    unsigned int strength;
    unsigned int dragons_count;

    cin >> strength >> dragons_count;

    vector<pair<unsigned int, unsigned int>> dragons(dragons_count);

    for (auto& dragon : dragons)
    {
        cin >> dragon.first >> dragon.second;
    }

    sort(dragons.begin(), dragons.end());

    for (const auto& dragon : dragons)
    {
        if (strength <= dragon.first)
        {
            cout << "NO\n";
            return 0;
        }

        strength += dragon.second;
    }

    cout << "YES\n";

    return 0;
}
