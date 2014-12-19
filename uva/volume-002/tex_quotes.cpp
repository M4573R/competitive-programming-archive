#include <iostream>
#include <string>
#include <vector>

using namespace std;

const unsigned int replacements_count {2};
const vector<char> replacements       {'`', '\''};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int replacement_index {0};

    for (string line; getline(cin, line);)
    {
        for (auto symbol : line)
        {
            if (symbol == '"')
            {
                cout << replacements[replacement_index]
                     << replacements[replacement_index];

                replacement_index += 1;
                replacement_index %= replacements_count;
            }
            else
            {
                cout << symbol;
            }
        }

        cout << '\n';
    }

    return 0;
}
