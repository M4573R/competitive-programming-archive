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

bool is_pangram(const string& sentence)
{
    set<char> used_letters;

    for (auto symbol : sentence)
    {
        if (isalpha(symbol))
        {
            used_letters.insert(tolower(symbol));
        }
    }

    return used_letters.size() == 26;
}

int main()
{
    use_io_optimizations();

    string sentence;
    getline(cin, sentence);

    cout << (is_pangram(sentence) ? "pangram" : "not pangram") << '\n';

    return 0;
}
