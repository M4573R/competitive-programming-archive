#include <cctype>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    bool new_sentence {true};

    for (char symbol; cin.get(symbol); )
    {
        cout << char(new_sentence ? toupper(symbol) : tolower(symbol));

        if (isalpha(symbol))
        {
            new_sentence = false;
        }

        if (symbol == '.' || symbol == '!' || symbol == '?')
        {
            new_sentence = true;
        }
    }

    return 0;
}
