#include <iostream>
#include <string>
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

    string sequence;
    cin >> sequence;

    vector<unsigned int> prefix_sums(sequence.size());

    for (string::size_type i {1}; i < sequence.size(); ++i)
    {
        prefix_sums[i] = prefix_sums[i - 1];

        if (sequence[i] == sequence[i - 1])
        {
            ++prefix_sums[i];
        }
    }

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int lower;
        unsigned int upper;

        cin >> lower >> upper;

        cout << prefix_sums[upper - 1] - prefix_sums[lower - 1] << '\n';
    }

    return 0;
}
