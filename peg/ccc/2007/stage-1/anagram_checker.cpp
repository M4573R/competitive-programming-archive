#include <algorithm>
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

    string first;
    string second;

    for (char symbol; cin.get(symbol) && symbol != '\n'; )
    {
        if (symbol != ' ')
        {
            first += symbol;
        }
    }

    for (char symbol; cin.get(symbol) && symbol != '\n'; )
    {
        if (symbol != ' ')
        {
            second += symbol;
        }
    }

    sort(first.begin(),  first.end());
    sort(second.begin(), second.end());

    cout << (first == second ? "Is an anagram" : "Is not an anagram") << ".\n";

    return 0;
}
