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

    unsigned int birthdays;
    cin >> birthdays;

    for (unsigned int i {0}; i < birthdays; ++i)
    {
        unsigned int year;
        unsigned int month;
        unsigned int day;

        cin >> year >> month >> day;

        if (year + 18 < 2007)
        {
            cout << "Yes";
        }
        else if (year + 18 == 2007)
        {
            if (month < 2)
            {
                cout << "Yes";
            }
            else if (month == 2 && day <= 27)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
        }
        else
        {
            cout << "No";
        }

        cout << '\n';
    }

    return 0;
}
