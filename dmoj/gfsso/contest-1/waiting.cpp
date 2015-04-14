#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
unsigned int to_seconds(unsigned int hour,
                        unsigned int minutes,
                        unsigned int seconds)
{
    return (hour * 60 + minutes) * 60 + seconds;
}

int main()
{
    use_io_optimizations();

    char delimiter;

    unsigned int begin_hour;
    unsigned int begin_minutes;
    unsigned int begin_seconds;

    cin >> begin_hour    >> delimiter
        >> begin_minutes >> delimiter
        >> begin_seconds;

    unsigned int end_hour;
    unsigned int end_minutes;
    unsigned int end_seconds;

    cin >> end_hour    >> delimiter
        >> end_minutes >> delimiter
        >> end_seconds;

    cout << to_seconds(end_hour,   end_minutes,   end_seconds) -
            to_seconds(begin_hour, begin_minutes, begin_seconds)
         << '\n';

    return 0;
}
