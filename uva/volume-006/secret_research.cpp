#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int results;
    cin >> results;

    for (unsigned int i {0}; i < results; ++i)
    {
        string sequence;
        cin >> sequence;

        if (sequence == "1" || sequence == "4" || sequence == "78")
        {
            cout << '+';
        }
        else if (sequence.substr(sequence.size() - 2) == "35")
        {
            cout << '-';
        }
        else if (sequence.front() == '9' && sequence.back() == '4')
        {
            cout << '*';
        }
        else
        {
            cout << '?';
        }

        cout << '\n';
    }

    return 0;
}
