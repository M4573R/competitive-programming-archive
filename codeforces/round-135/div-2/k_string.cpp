#include <iostream>
#include <map>
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

    unsigned int parts;
    string sequence;

    cin >> parts >> sequence;

    map<char, unsigned int> count;

    for (auto element : sequence)
    {
        ++count[element];
    }

    string part;

    for (char letter {'a'}; letter <= 'z'; ++letter)
    {
        if (count[letter] % parts)
        {
            cout << -1 << '\n';
            return 0;
        }

        part += string(count[letter] / parts, letter);
    }

    for (unsigned int i {0}; i < parts; ++i)
    {
        cout << part;
    }

    cout << '\n';

    return 0;
}
