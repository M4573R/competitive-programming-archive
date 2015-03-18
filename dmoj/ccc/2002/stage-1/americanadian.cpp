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
    static const set<char> vowels {'a', 'e', 'i', 'o', 'u', 'y'};

    return vowels.count(tolower(symbol));
}

inline
bool is_consonant(char symbol)
{
    return isalpha(symbol) && !is_vowel(symbol);
}

inline
bool is_american(const string& word)
{
    auto length = word.length();

    return (length > 4 &&
            is_consonant(word[length - 3]) &&
            word.substr(length - 2) == "or");
}

int main()
{
    use_io_optimizations();

    for (string word; cin >> word && word != "quit!"; )
    {
        if (is_american(word))
        {
            word.insert(word.size() - 1, "u");
        }

        cout << word << '\n';
    }

    return 0;
}
