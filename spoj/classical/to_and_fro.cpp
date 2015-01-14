#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    string::size_type columns;

    while (cin >> columns && columns != 0)
    {
        string cyphertext;
        cin >> cyphertext;

        string plaintext;
        string::size_type rows = cyphertext.length() / columns;

        for (string::size_type i = 0; i < columns; ++i)
        {
            plaintext += cyphertext[i];

            for (string::size_type j = i + 2 * (columns - i) - 1;
                 j < cyphertext.length();
                 j += 2 * columns)
            {
                plaintext += cyphertext[j];
                plaintext += cyphertext[j + 2 * i + 1];
            }
        }

        cout << plaintext << '\n';
    }

    return 0;
}
