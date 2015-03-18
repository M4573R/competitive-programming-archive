#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const string alphabet {"abcdefghijklmnopqrstuvwxyz"};

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
    cin.ignore();

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string answer;
        getline(cin, answer);

        sort(answer.begin(), answer.end());

        cout << (answer == alphabet ? "OK" : "Nope") << ".\n";
    }

    return 0;
}
