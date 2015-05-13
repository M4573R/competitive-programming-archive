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

    unsigned int sensors;
    cin >> sensors;

    vector<int> prefix_sums(sensors + 1);

    for (unsigned int i {1}; i <= sensors; ++i)
    {
        cin >> prefix_sums[i];
        prefix_sums[i] += prefix_sums[i - 1];
    }

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int lower;
        unsigned int upper;

        cin >> lower >> upper;

        cout << prefix_sums[upper] - prefix_sums[lower - 1] << '\n';
    }

    return 0;
}
