#include <algorithm>
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
        string word;
        cin >> word;

        if (next_permutation(word.begin(), word.end()))
        {
            cout << word << '\n';
        }
        else
        {
            cout << "no answer\n";
        }
    }

    return 0;
}
