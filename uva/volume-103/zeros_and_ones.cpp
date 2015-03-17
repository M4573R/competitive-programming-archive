#include <algorithm>
#include <iostream>
#include <string>

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

    string bits;
    unsigned int queries;

    for (unsigned int test {1}; cin >> bits >> queries; ++test)
    {
        vector<int> changes(bits.size());

        for (string::size_type i {1}; i < bits.size(); ++i)
        {
            changes[i] += changes[i - 1] + (bits[i] != bits[i - 1]);
        }

        cout << "Case " << test << ":\n";

        for (unsigned int i {0}; i < queries; ++i)
        {
            unsigned int left;
            unsigned int right;

            cin >> left >> right;

            if (left > right)
            {
                swap(left, right);
            }

            cout << (changes[right] == changes[left] ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}
