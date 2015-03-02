#include <cctype>
#include <iostream>
#include <set>

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

    string text;
    cin >> text;

    set<char> letters;

    for (auto letter : text)
    {
        letters.insert(tolower(letter));
    }

    cout << (letters.size() == 26 ? "YES" : "NO") << '\n';

    return 0;
}
