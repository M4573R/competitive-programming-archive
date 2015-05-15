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

    vector<unsigned int> prefix_sums(length + 1);

    for (unsigned int i {1}; i <= length; ++i)
    {
        unsigned int element;
        cin >> element;

        prefix_sums[i] = prefix_sums[i - 1] + element;
    }

    unsigned int first;
    unsigned int second;

    cin >> first >> second;

    if (first < second)
    {
        unsigned int middle {(first + second) / 2};

        cout << prefix_sums[middle]                       << ' '
             << prefix_sums[length] - prefix_sums[middle] << '\n';
    }
    else if (first > second)
    {
        unsigned int middle {(first + second + 1) / 2};

        cout << prefix_sums[length] - prefix_sums[middle - 1] << ' '
             << prefix_sums[middle - 1]                       << '\n';
    }
    else
    {
        unsigned int middle {(first + second) / 2};

        cout << max(prefix_sums[length] - prefix_sums[middle - 1],
                    prefix_sums[middle])     << ' '
             << min(prefix_sums[length] - prefix_sums[middle],
                    prefix_sums[middle - 1]) << '\n';
    }

    return 0;
}
