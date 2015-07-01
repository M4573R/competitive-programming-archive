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

    unsigned int start_hour;
    unsigned int start_minute;

    unsigned int end_hour;
    unsigned int end_minute;

    while (cin >> start_hour >> start_minute >> end_hour >> end_minute &&
           (start_hour || start_minute || end_hour || end_minute))
    {
        unsigned int start_in_minutes {60 * start_hour + start_minute};
        unsigned int end_in_minutes   {60 * end_hour   + end_minute};

        if (start_in_minutes < end_in_minutes)
        {
            cout << end_in_minutes - start_in_minutes;
        }
        else
        {
            cout << 24 * 60 + end_in_minutes - start_in_minutes;
        }

        cout << '\n';
    }

    return 0;
}
