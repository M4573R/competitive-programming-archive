#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_palindrome(const string& sequence)
{
    for (string::size_type i {0}; i < sequence.size() / 2; ++i)
    {
        if (sequence[i] != sequence[sequence.size() - 1 - i])
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

        int index {-1};

        for (string::size_type i {0}; i < sequence.size() / 2; ++i)
        {
            if (sequence[i] != sequence[sequence.size() - 1 - i])
            {
                if (is_palindrome(sequence.substr(0, i) +
                                  sequence.substr(i + 1)))
                {
                    index = i;
                }
                else
                {
                    index = sequence.size() - 1 - i;
                }

                break;
            }
        }

        cout << index << '\n';
    }

    return 0;
}
