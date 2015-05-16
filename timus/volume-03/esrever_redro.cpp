#include <algorithm>
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

    string word;

    for (char symbol; cin.get(symbol); )
    {
        if (isalpha(symbol))
        {
            word += symbol;
        }
        else
        {
            reverse(word.begin(), word.end());
            cout << word << symbol;
            word.clear();
        }
    }

    reverse(word.begin(), word.end());
    cout << word;

    return 0;
}
