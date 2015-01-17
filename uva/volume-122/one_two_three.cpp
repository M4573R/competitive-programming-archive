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

    unsigned int words;
    cin >> words;

    for (unsigned int i {0}; i < words; ++i)
    {
        string word;
        cin >> word;

        if (word.length() == 5)
        {
            cout << 3;
        }
        else
        {
            unsigned int matches {(word[0] == 'o') +
                                  (word[1] == 'n') +
                                  (word[2] == 'e')};

            cout << (matches >= 2 ? 1 : 2);
        }

        cout << '\n';
    }

    return 0;
}
