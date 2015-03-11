#include <algorithm>
#include <cctype>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string symbols;
        cin >> symbols;

        transform(symbols.begin(), symbols.end(), symbols.begin(), ::tolower);

        cout << symbols << '\n';
    }

    return 0;
}
