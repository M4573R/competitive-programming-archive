#include <algorithm>
#include <iostream>
#include <numeric>

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

    unsigned int flowers;
    cin >> flowers;

    vector<unsigned int> values(flowers);

    for (auto& value : values)
    {
        cin >> value;
    }

    unsigned int pairs;
    cin >> pairs;

    unsigned int max_harmony {accumulate(values.cbegin(), values.cend(), 0u)};

    for (unsigned int i {0}; i < pairs; ++i)
    {
        unsigned int index;
        unsigned int decrease;

        cin >> index >> decrease;

        max_harmony -= min({values[index - 1], values[index], decrease});
    }

    cout << max_harmony << '\n';

    return 0;
}
