#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

    map<char, unsigned int> frequencies;
    frequencies['a'] = 0;
    frequencies['b'] = 0;
    frequencies['g'] = 0;
    frequencies['i'] = 0;
    frequencies['n'] = 0;
    frequencies['z'] = 0;

    string banner;
    getline(cin, banner);

    for (string::const_iterator letter = banner.begin();
         letter != banner.end();
         ++letter)
    {
        char lowercased = tolower(*letter);

        if (frequencies.count(lowercased))
        {
            ++frequencies[lowercased];
        }
    }

    frequencies['a'] /= 2;

    cout << min_element(frequencies.begin(),
                        frequencies.end(),
                        BySecond())->second
         << '\n';

    return 0;
}
