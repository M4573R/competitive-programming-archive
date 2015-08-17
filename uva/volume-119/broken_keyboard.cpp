#include <iostream>
#include <list>
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

    for (string line; cin >> line; )
    {
        list<char> text;
        auto cursor = text.begin();

        for (auto symbol : line)
        {
            if (symbol == '[')
            {
                cursor = text.begin();
            }
            else if (symbol == ']')
            {
                cursor = text.end();
            }
            else
            {
                text.insert(cursor, symbol);
            }
        }

        for (auto symbol : text)
        {
            cout << symbol;
        }

        cout << '\n';
    }

    return 0;
}
