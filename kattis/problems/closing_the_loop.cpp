#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(vector<unsigned int>& red, vector<unsigned int>& blue)
{
    unsigned int segments;
    cin >> segments;

    for (unsigned int i {0}; i < segments; ++i)
    {
        unsigned int length;
        char color;

        cin >> length >> color;

        if (color == 'R')
        {
            red.push_back(length);
        }
        else
        {
            blue.push_back(length);
        }
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        vector<unsigned int> red;
        vector<unsigned int> blue;

        read_input(red, blue);

        sort(red.begin(),  red.end(),  greater<unsigned int>());
        sort(blue.begin(), blue.end(), greater<unsigned int>());

        auto pairs = min(red.size(), blue.size());

        unsigned int loop_length {
            accumulate(red.cbegin(),  red.cbegin()  + pairs, 0u) +
            accumulate(blue.cbegin(), blue.cbegin() + pairs, 0u) -
            2 * pairs
        };

        cout << "Case #" << test << ": " << loop_length << '\n';
    }

    return 0;
}
