#include <cctype>
#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    for (string line; getline(cin, line);)
    {
        bool in_word {false};
        unsigned int words {0};

        for (auto symbol : line)
        {
            if (isalpha(symbol) && !in_word)
            {
                in_word = true;
            }

            if (!isalpha(symbol) && in_word)
            {
                in_word = false;
                ++words;
            }
        }

        cout << words << '\n';
    }

    return 0;
}
