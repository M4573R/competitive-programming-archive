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

    string message;
    getline(cin, message);

    unsigned int positive {0};
    unsigned int negative {0};

    for (string::size_type i {0}; i < message.size() - 2; ++i)
    {
        if (message.substr(i, 3) == ":-)")
        {
            ++positive;
        }
        else if (message.substr(i, 3) == ":-(")
        {
            ++negative;
        }
    }

    if (positive == 0 && negative == 0)
    {
        cout << "none\n";
    }
    else if (positive > negative)
    {
        cout << "happy\n";
    }
    else if (positive < negative)
    {
        cout << "sad\n";
    }
    else
    {
        cout << "unsure\n";
    }

    return 0;
}
