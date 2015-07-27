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

int main()
{
    use_io_optimizations();

    unsigned int length;
    cin >> length;

    string ciphertext;
    cin >> ciphertext;

    unsigned int shift;
    cin >> shift;

    for (auto symbol : ciphertext)
    {
        if (islower(symbol))
        {
            cout << static_cast<char>('a' + (symbol - 'a' + shift) % 26);
        }
        else if (isupper(symbol))
        {
            cout << static_cast<char>('A' + (symbol - 'A' + shift) % 26);
        }
        else
        {
            cout << symbol;
        }
    }

    cout << '\n';

    return 0;
}
