#include <iomanip>
#include <iostream>

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

    cout << setfill('0');

    char delimiter;

    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;

    string specifier;

    cin >> hours   >> delimiter
        >> minutes >> delimiter
        >> seconds >> specifier;

    if (specifier == "AM" && hours == 12)
    {
        hours = 0;
    }

    if (specifier == "PM" && hours != 12)
    {
        hours += 12;
    }

    cout << setw(2) << hours   << ':'
         << setw(2) << minutes << ':'
         << setw(2) << seconds << '\n';

    return 0;
}
