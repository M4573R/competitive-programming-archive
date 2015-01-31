#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const unsigned int max_color = 26;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        string colors;
        cin >> colors;

        vector<unsigned int> count(max_color);

        for (string::size_type i = 0; i < colors.size(); ++i)
        {
            ++count[colors[i] - 'a'];
        }

        cout << *max_element(count.begin(), count.end()) << '\n';
    }

    return 0;
}
