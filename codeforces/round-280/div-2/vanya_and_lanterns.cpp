#include <algorithm>
#include <iomanip>
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

    cout << fixed << setprecision(12);

    unsigned int lanterns;
    unsigned int length;

    cin >> lanterns >> length;

    vector<unsigned int> positions(lanterns);

    for (auto& position : positions)
    {
        cin >> position;
    }

    sort(positions.begin(), positions.end());

    unsigned int max_distance {
        2 * max(positions.front(), length - positions.back())
    };

    for (unsigned int i {0}; i < lanterns - 1; ++i)
    {
        max_distance = max(max_distance, positions[i + 1] - positions[i]);
    }

    cout << max_distance / 2.0 << '\n';

    return 0;
}
