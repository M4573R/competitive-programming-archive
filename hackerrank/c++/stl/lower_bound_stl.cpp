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

    for (auto& element : sequence)
    {
        cin >> element;
    }

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int element;
        cin >> element;

        auto position = lower_bound(sequence.cbegin(), sequence.cend(), element);

        cout << (*position == element ? "Yes" : "No") << ' '
             << position - sequence.cbegin() + 1      << '\n';
    }

    return 0;
}
