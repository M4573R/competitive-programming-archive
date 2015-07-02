#include <algorithm>
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

string invert_cases(const string& word)
{
    string inverted_cases {word};

    for (char& symbol : inverted_cases)
    {
        if (islower(symbol))
        {
            symbol = toupper(symbol);
        }
        else if (isupper(symbol))
        {
            symbol = tolower(symbol);
        }
    }

    return inverted_cases;
}

int main()
{
    use_io_optimizations();

    string word;
    cin >> word;

    if (find_if(word.cbegin() + 1, word.cend(), ::islower) == word.cend())
    {
        cout << invert_cases(word);
    }
    else
    {
        cout << word;
    }

    cout << '\n';

    return 0;
}
