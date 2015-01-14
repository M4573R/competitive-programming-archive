#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

unsigned int longest_increasing_subsequence(const vector<unsigned int>& sequence)
{
    unsigned int max_length = 0;
    vector<unsigned int> min_tails(sequence.size() + 1);

    for (vector<unsigned int>::size_type i = 0; i < sequence.size(); ++i)
    {
        unsigned int low  = 1;
        unsigned int high = max_length;

        while (low <= high)
        {
            unsigned int middle = (low + high) / 2;

            if (sequence[min_tails[middle]] < sequence[i])
            {
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
        }

        min_tails[low] = i;
        max_length = max(max_length, low);
    }

    return max_length;
}

int main()
{
    use_io_optimizations();

    unsigned int length;
    cin >> length;

    vector<unsigned int> sequence(length);

    for (unsigned int i = 0; i < length; ++i)
    {
        cin >> sequence[i];
    }

    cout << longest_increasing_subsequence(sequence) << '\n';

    return 0;
}
