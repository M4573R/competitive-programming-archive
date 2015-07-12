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

    unsigned int people;
    unsigned int capacity;

    cin >> people >> capacity;

    vector<unsigned int> floors(people);

    for (auto& floor : floors)
    {
        cin >> floor;
    }

    sort(floors.begin(), floors.end());

    unsigned int min_time {0};

    for (int i = people - 1; i >= 0; i -= capacity)
    {
        min_time += 2 * (floors[i] - 1);
    }

    cout << min_time << '\n';

    return 0;
}
