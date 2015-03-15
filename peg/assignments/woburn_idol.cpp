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
    static const set<char> vowels {'a', 'e', 'i', 'o', 'u'};

    return vowels.count(tolower(symbol));
}

int main()
{
    use_io_optimizations();

    string name;
    cin >> name;

    unsigned int a_count     {0};
    unsigned int other_count {0};

    for (auto& symbol : name)
    {
        if (is_vowel(symbol))
        {
            if (symbol == 'a' || symbol == 'A')
            {
                ++a_count;
            }
            else
            {
                ++other_count;
            }
        }
    }

    if (a_count >= other_count)
    {
        cout << "Advance to next round";
    }
    else
    {
        cout << "Does not advance to next round";
    }

    cout << '\n';

    return 0;
}
