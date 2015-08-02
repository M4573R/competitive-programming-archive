#include <algorithm>
#include <iostream>
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
        string sequence;
        cin >> sequence;

        if (sequence.size() % 2)
        {
            cout << -1 << '\n';
            continue;
        }

        multiset<char> first(sequence.cbegin(),
                             sequence.cbegin() + sequence.size() / 2);

        multiset<char> second(sequence.cbegin() + sequence.size() / 2,
                              sequence.cend());

        multiset<char> difference;

        set_difference(first.cbegin(),  first.cend(),
                       second.cbegin(), second.cend(),
                       inserter(difference, difference.begin()));

        cout << difference.size() << '\n';
    }

    return 0;
}
