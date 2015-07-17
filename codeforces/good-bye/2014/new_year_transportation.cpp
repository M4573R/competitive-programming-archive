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

    unsigned int cells;
    unsigned int target;

    cin >> cells >> target;

    vector<unsigned int> portals(cells - 1);

    for (auto& portal : portals)
    {
        cin >> portal;
    }

    unsigned int cell {0};

    while (cell < target - 1)
    {
        cell += portals[cell];
    }

    cout << (cell == target - 1 ? "YES" : "NO") << '\n';

    return 0;
}
