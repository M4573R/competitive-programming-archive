#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline bool is_vowel(char symbol)
{
    static set<char> vowels = {
        'a', 'o', 'y', 'e', 'u', 'i', 'A', 'O', 'Y', 'E', 'U', 'I'
    };

    return vowels.find(symbol) != vowels.end();
}

inline bool is_consonant(char symbol)
{
    return isalpha(symbol) && !is_vowel(symbol);
}

int main()
{
    use_io_optimizations();

    string input;
    cin >> input;

    string output;

    for (string::const_iterator i = input.cbegin(); i != input.cend(); ++i)
    {
        if (is_consonant(*i))
        {
            output += '.';
            output += tolower(*i);
        }
    }

    cout << output << '\n';

    return 0;
}
