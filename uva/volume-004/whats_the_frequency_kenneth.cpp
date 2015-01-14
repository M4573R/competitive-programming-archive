#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class BySecond
{
public:
    bool operator()(const pair<char, unsigned int>& left,
                    const pair<char, unsigned int>& right)
    {
        return left.second < right.second;
    }
};

int main()
{
    use_io_optimizations();

    for (string line; getline(cin, line);)
    {
        map<char, unsigned int> frequencies;

        for (auto symbol : line)
        {
            if (isalpha(symbol))
            {
                ++frequencies[symbol];
            }
        }

        unsigned int max_frequency {
            max_element(frequencies.begin(),
                        frequencies.end(),
                        BySecond())->second
        };

        for (auto& symbol_and_frequency : frequencies)
        {
            char symbol            {symbol_and_frequency.first};
            unsigned int frequency {symbol_and_frequency.second};

            if (frequency == max_frequency)
            {
                cout << symbol;
            }
        }

        cout << ' ' << max_frequency << '\n';
    }

    return 0;
}
