#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> restore_array(const vector<unsigned int>& subset_sums)
{
    vector<unsigned int> array;

    vector<unsigned int>            seen(subset_sums.size());
    vector<unsigned int>::size_type seen_count {0};

    multiset<unsigned int> expected;

    for (auto sum = subset_sums.cbegin() + 1; sum != subset_sums.cend(); ++sum)
    {
        if (!expected.empty() && *expected.begin() == *sum)
        {
            expected.erase(expected.begin());
        }
        else
        {
            array.push_back(*sum);

            auto old_count     = seen_count;
            seen[seen_count++] = *sum;

            for (vector<unsigned int>::size_type i = 0; i < old_count; ++i)
            {
                seen[seen_count] = seen[i] + *sum;
                expected.insert(seen[seen_count]);
                ++seen_count;
            }
        }
    }

    return array;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int array_size;
        cin >> array_size;

        vector<unsigned int> subset_sums(1 << array_size);

        for (unsigned int j {0}; j < (1 << array_size); ++j)
        {
            cin >> subset_sums[j];
        }

        sort(subset_sums.begin(), subset_sums.end());

        vector<unsigned int> array {restore_array(subset_sums)};

        for (auto element = array.cbegin(); element != array.cend(); ++element)
        {
            cout << *element;

            if (element < array.cend() - 1)
            {
                cout << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
