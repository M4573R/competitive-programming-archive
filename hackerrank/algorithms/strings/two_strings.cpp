#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string first;
        string second;

        cin >> first >> second;

        sort(first.begin(),  first.end());
        sort(second.begin(), second.end());

        vector<char> intersection;

        set_intersection(first.cbegin(),  first.cend(),
                         second.cbegin(), second.cend(),
                         back_inserter(intersection));

        cout << (intersection.empty() ? "NO" : "YES") << '\n';
    }

    return 0;
}
