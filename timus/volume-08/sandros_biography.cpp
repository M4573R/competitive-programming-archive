#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

constexpr unsigned int edit_cost {5};

const string name {"Sandro"};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int edit_price(const string& text)
{
    unsigned int coins {0};

    for (string::size_type i {0}; i < name.size(); ++i)
    {
        if (isupper(text[i]) != isupper(name[i]))
        {
            coins += edit_cost;
        }

        if (toupper(text[i]) != toupper(name[i]))
        {
            coins += edit_cost;
        }
    }

    return coins;
}

int main()
{
    use_io_optimizations();

    string manuscript;
    cin >> manuscript;

    unsigned int min_price {numeric_limits<unsigned int>::max()};

    for (string::size_type i {0}; i <= manuscript.size() - name.size(); ++i)
    {
        min_price = min(min_price,
                        edit_price(manuscript.substr(i, name.size())));
    }

    cout << min_price << '\n';

    return 0;
}
