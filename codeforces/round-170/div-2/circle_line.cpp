#include <algorithm>
#include <iostream>

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

    unsigned int stations;
    cin >> stations;

    vector<unsigned int> distances(stations + 1);

    for (unsigned int i {1}; i <= stations; ++i)
    {
        cin >> distances[i];
        distances[i] += distances[i - 1];
    }

    unsigned int from;
    unsigned int to;

    cin >> from >> to;

    if (from > to)
    {
        swap(from, to);
    }

    cout << min(distances[to - 1] - distances[from - 1],
                distances[stations] - distances[to - 1] + distances[from - 1])
         << '\n';

    return 0;
}
