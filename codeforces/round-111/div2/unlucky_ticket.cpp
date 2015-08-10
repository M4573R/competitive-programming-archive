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

    unsigned int half;
    cin >> half;

    string digits;
    cin >> digits;

    sort(digits.begin(), digits.begin() + half);
    sort(digits.begin() + half, digits.end());

    bool is_strictly_less {true};
    bool is_strictly_more {true};

    for (unsigned int i {0}; i < half; ++i)
    {
        if (digits[i] >= digits[half + i])
        {
            is_strictly_less = false;
        }

        if (digits[i] <= digits[half + i])
        {
            is_strictly_more = false;
        }
    }

    cout << (is_strictly_less || is_strictly_more ? "YES" : "NO") << '\n';

    return 0;
}
