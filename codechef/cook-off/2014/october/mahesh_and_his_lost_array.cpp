#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> restore_array(const vector<unsigned int>& subset_sums)
{
    vector  <unsigned int> array;
    vector  <unsigned int> seen;
    multiset<unsigned int> expected;

    for (auto sum = subset_sums.cbegin() + 1; sum != subset_sums.cend(); ++sum)
    {
        if (!expected.empty() && *expected.cbegin() == *sum)
        {
            expected.erase(expected.begin());
        }
        else
        {
            array.push_back(*sum);
            seen.push_back(*sum);

            for (unsigned int i {0}, j {seen.size()}; i + 1 < j; ++i)
            {
                seen.push_back(*sum + seen[i]);
                expected.insert(*sum + seen[i]);
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

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int elements;
        cin >> elements;

        vector<unsigned int> subset_sums(1 << elements);

        for (auto& sum : subset_sums)
        {
            cin >> sum;
        }

        sort(subset_sums.begin(), subset_sums.end());

        vector<unsigned int> array {restore_array(subset_sums)};

        for (auto i = array.cbegin(); i != array.cend(); ++i)
        {
            cout << *i << " \n"[i + 1 == array.cend()];
        }
    }

    return 0;
}
