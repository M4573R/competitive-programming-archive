#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int trees;
    cin >> trees;

    vector<unsigned int> prefix_sums(trees + 1);

    for (unsigned int i {1}; i <= trees; ++i)
    {
        unsigned int mass;
        cin >> mass;

        prefix_sums[i] = prefix_sums[i - 1] + mass;
    }

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        cout << prefix_sums[to + 1] - prefix_sums[from] << '\n';
    }

    return 0;
}
