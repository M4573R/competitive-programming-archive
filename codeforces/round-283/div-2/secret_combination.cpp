#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int digits_count;
    cin >> digits_count;

    string digits;
    cin >> digits;

    string min_number {digits};

    for (unsigned int shifts {0}; shifts < digits_count; ++shifts)
    {
        string amended {digits.substr(shifts) + digits.substr(0, shifts)};

        unsigned int additions = 10 - (amended.front() - '0');

        for (auto& digit : amended)
        {
            digit = (digit - '0' + additions) % 10 + '0';
        }

        min_number = min(min_number, amended);
    }

    cout << min_number << '\n';

    return 0;
}
