#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_funny(const string& sequence)
{
    auto length = sequence.length();

    for (string::size_type i {1}; i <= length / 2; ++i)
    {
        if (abs(sequence[i] - sequence[i - 1]) !=
            abs(sequence[length - i - 1] - sequence[length - i]))
        {
            return false;
        }
    }

    return true;
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

        cout << (is_funny(sequence) ? "Funny" : "Not Funny") << '\n';
    }

    return 0;
}
