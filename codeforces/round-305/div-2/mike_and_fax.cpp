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

    string sequence;
    cin >> sequence;

    unsigned int messages;
    cin >> messages;

    if (sequence.size() % messages)
    {
        cout << "NO\n";
        return 0;
    }

    unsigned int length {sequence.size() / messages};

    for (string::size_type i {0}; i < sequence.size(); i += length)
    {
        if (!is_palindrome(sequence.substr(i, length)))
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
