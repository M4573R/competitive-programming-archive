#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline bool max_frequency_min_value(const pair<unsigned int, unsigned int>& left,
                                    const pair<unsigned int, unsigned int>& right)
{
    return left.second < right.second || left.first > right.first;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int length;
        cin >> length;

        map<unsigned int, unsigned int> frequencies;

        for (unsigned int j {0}; j < length; ++j)
        {
            unsigned int element;
            cin >> element;

            ++frequencies[element];
        }

        auto element_and_frequency = max_element(frequencies.cbegin(),
                                                 frequencies.cend(),
                                                 max_frequency_min_value);

        cout << element_and_frequency->first
             << ' '
             << element_and_frequency->second
             << '\n';
    }

    return 0;
}
