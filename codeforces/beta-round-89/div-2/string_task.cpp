#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
bool is_vowel(char symbol)
{
    static set<char> vowels {
        'a', 'o', 'y', 'e', 'u', 'i', 'A', 'O', 'Y', 'E', 'U', 'I'
    };

    return vowels.count(symbol);
}

inline
bool is_consonant(char symbol)
{
    return isalpha(symbol) && !is_vowel(symbol);
}

int main()
{
    use_io_optimizations();

    string input;
    cin >> input;

    string output;

    for (auto symbol : input)
    {
        if (is_consonant(symbol))
        {
            output += '.';
            output += tolower(symbol);
        }
    }

    cout << output << '\n';

    return 0;
}
