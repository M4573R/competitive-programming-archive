#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_caps_locked(const string& word)
{
    if (word.length() == 0)
    {
        return false;
    }

    if (word.length() == 1)
    {
        return true;
    }

    if (islower(word.front()))
    {
        return find_if(++word.cbegin(), word.cend(), ::islower) == word.cend();
    }

    if (isupper(word.front()))
    {
        return find_if(++word.cbegin(), word.cend(), ::islower) == word.cend();
    }

    return false;
}

string change_cases(const string& word)
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

    if (is_caps_locked(word))
    {
        cout << change_cases(word) << '\n';
    }
    else
    {
        cout << word << '\n';
    }

    return 0;
}
