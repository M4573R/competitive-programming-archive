#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class BySecond
{
public:
    bool operator()(const pair<string, unsigned int>& left,
                    const pair<string, unsigned int>& right)
    {
        return left.second < right.second;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int entries;
    cin >> entries;
    cin.get();

    map<string, unsigned int> frequencies;

    for (unsigned int i {0}; i < entries; ++i)
    {
        string breed;
        getline(cin, breed);

        ++frequencies[breed];
    }

    cout << max_element(frequencies.cbegin(),
                        frequencies.cend(),
                        BySecond())->first
         << '\n';

    return 0;
}
