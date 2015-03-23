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
        unsigned int length;
        unsigned int ones;

        cin >> length >> ones;

        string pattern {string(ones, '1') + string(length - ones, '0')};

        cout << "The bit patterns are\n";

        do
        {
            cout << pattern << '\n';

        } while (prev_permutation(pattern.begin(), pattern.end()));

        cout << '\n';
    }

    return 0;
}
