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

    unsigned int length;
    cin >> length;

    vector<unsigned int> sequence(length);

    for (auto& number : sequence)
    {
        cin >> number;
    }

    vector<unsigned int> max_sums(length + 2);

    for (unsigned int i {0}; i < length; ++i)
    {
        max_sums[i + 2] = max(max_sums[i + 1], max_sums[i] + sequence[i]);
    }

    cout << max_sums.back() << '\n';

    return 0;
}
