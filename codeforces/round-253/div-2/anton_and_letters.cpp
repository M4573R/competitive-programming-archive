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

    set<char> letters;

    for (char symbol; cin >> symbol; )
    {
        if (isalpha(symbol))
        {
            letters.insert(symbol);
        }
    }

    cout << letters.size() << '\n';

    return 0;
}
