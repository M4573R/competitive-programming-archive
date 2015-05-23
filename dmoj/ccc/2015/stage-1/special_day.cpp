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

    unsigned int month;
    unsigned int day;

    cin >> month >> day;

    if (month == 2 && day == 18)
    {
        cout << "Special";
    }
    else if (month < 2 || (month == 2 && day < 18))
    {
        cout << "Before";
    }
    else
    {
        cout << "After";
    }

    cout << '\n';

    return 0;
}
