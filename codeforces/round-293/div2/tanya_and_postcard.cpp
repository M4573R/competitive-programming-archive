#include <cctype>
#include <iostream>
#include <map>
#include <string>

using namespace std;

constexpr char found_symbol {'#'};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline char opposite(char symbol)
{
    return islower(symbol) ? toupper(symbol) : tolower(symbol);
}

int main()
{
    use_io_optimizations();

    string message;
    string newspaper;

    cin >> message >> newspaper;

    map<char, unsigned int> frequencies;

    for (auto symbol : newspaper)
    {
        ++frequencies[symbol];
    }

    unsigned int yay_count   {0};
    unsigned int woops_count {0};

    for (auto& symbol : message)
    {
        if (frequencies[symbol])
        {
            ++yay_count;
            --frequencies[symbol];
            symbol = found_symbol;
        }
    }

    for (auto symbol : message)
    {
        if (symbol != found_symbol && frequencies[opposite(symbol)])
        {
            ++woops_count;
            --frequencies[opposite(symbol)];
        }
    }

    cout << yay_count << ' ' << woops_count << '\n';

    return 0;
}
