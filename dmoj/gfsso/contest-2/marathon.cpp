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

    unsigned int episodes;
    unsigned int queries;

    cin >> episodes >> queries;

    vector<unsigned int> prefix_sums(episodes + 1);

    for (unsigned int i {0}; i < episodes; ++i)
    {
        unsigned int rating;
        cin >> rating;

        prefix_sums[i + 1] = prefix_sums[i] + rating;
    }

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        unsigned missed {prefix_sums[to] - prefix_sums[from - 1]};

        cout << prefix_sums[episodes] - missed << '\n';
    }

    return 0;
}
