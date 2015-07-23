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

    vector<double> distances(301);

    distances[1] = 0.5;

    for (unsigned int i {2}; i <= 300; ++i)
    {
        distances[i] = distances[i - 1] + 1.0 / (i + 1);
    }

    for (double distance; cin >> distance && distance != 0; )
    {
        cout << (lower_bound(distances.cbegin(),
                             distances.cend(),
                             distance) -
                 distances.cbegin())
             << " card(s)\n";
    }

    return 0;
}
