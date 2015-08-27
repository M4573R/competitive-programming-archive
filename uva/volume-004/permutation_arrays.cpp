#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        cin.ignore(2);

        string line;
        getline(cin, line);

        istringstream in {line};
        vector<pair<unsigned int, string>> permutation;

        for (unsigned int index; in >> index; )
        {
            permutation.emplace_back(index, "");
        }

        for (auto& element : permutation)
        {
            cin >> element.second;
        }

        sort(permutation.begin(), permutation.end());

        for (auto& element : permutation)
        {
            cout << element.second << '\n';
        }

        if (test < test_cases - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
