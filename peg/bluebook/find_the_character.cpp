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

    char wanted;
    cin >> wanted;
    cin.ignore();

    string sentence;
    getline(cin, sentence, '.');

    unsigned int occurrences {0};

    for (auto symbol : sentence)
    {
        if (tolower(symbol) == tolower(wanted))
        {
            ++occurrences;
        }
    }

    cout << sentence    << '\n'
         << occurrences << '\n';

    return 0;
}
