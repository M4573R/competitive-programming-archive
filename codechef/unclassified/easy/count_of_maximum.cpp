#include <algorithm>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct MaxFrequencyMinValue
{
    bool operator()(const pair<unsigned int, unsigned int>& left,
                    const pair<unsigned int, unsigned int>& right)
    {
        if (left.second == right.second)
        {
            return left.first > right.first;
        }

        return left.second < right.second;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int values;
        cin >> values;

        map<unsigned int, unsigned int> frequencies;

        for (unsigned int i {0}; i < values; ++i)
        {
            unsigned int value;
            cin >> value;

            ++frequencies[value];
        }

        auto value_and_frequency = max_element(frequencies.cbegin(),
                                               frequencies.cend(),
                                               MaxFrequencyMinValue());

        cout << value_and_frequency->first  << ' '
             << value_and_frequency->second << '\n';
    }

    return 0;
}
