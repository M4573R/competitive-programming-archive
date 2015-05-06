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

    unsigned int product;
    cin >> product;

    if (product == 0)
    {
        cout << 10 << '\n';
    }
    else if (product == 1)
    {
        cout << 1 << '\n';
    }
    else
    {
        string number;

        for (unsigned int digit {9}; digit >= 2; --digit)
        {
            while (product % digit == 0)
            {
                number  += static_cast<char>(digit + '0');
                product /= digit;
            }
        }

        reverse(number.begin(), number.end());

        cout << (product == 1 ? number : "-1") << '\n';
    }

    return 0;
}
