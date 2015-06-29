#include <iostream>

using namespace std;

constexpr unsigned int seconds_per_minute {60};
constexpr unsigned int seconds_per_hour   {60 * seconds_per_minute};
constexpr unsigned int seconds_per_day    {24 * seconds_per_hour};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
unsigned int to_seconds(unsigned int day,
                        unsigned int hour,
                        unsigned int minute,
                        unsigned int second)
{
    return (day    * seconds_per_day    +
            hour   * seconds_per_hour   +
            minute * seconds_per_minute +
            second);
}

inline
unsigned int days(unsigned int seconds)
{
    return seconds / seconds_per_day;
}

inline
unsigned int hours(unsigned int seconds)
{
    return seconds % seconds_per_day / seconds_per_hour;
}

inline
unsigned int minutes(unsigned int seconds)
{
    return seconds % seconds_per_hour / seconds_per_minute;
}

inline
unsigned int seconds(unsigned int seconds)
{
    return seconds % seconds_per_minute;
}

int main()
{
    use_io_optimizations();

    string delimiter;

    unsigned int start_day;
    unsigned int start_hour;
    unsigned int start_minute;
    unsigned int start_second;

    unsigned int end_day;
    unsigned int end_hour;
    unsigned int end_minute;
    unsigned int end_second;

    cin >> delimiter >> start_day
                     >> start_hour
        >> delimiter >> start_minute
        >> delimiter >> start_second;

    cin >> delimiter >> end_day
                     >> end_hour
        >> delimiter >> end_minute
        >> delimiter >> end_second;

    unsigned int duration {to_seconds(end_day,
                                      end_hour,
                                      end_minute,
                                      end_second)-
                           to_seconds(start_day,
                                      start_hour,
                                      start_minute,
                                      start_second)};

    cout << days(duration)    << " dia(s)\n"
         << hours(duration)   << " hora(s)\n"
         << minutes(duration) << " minuto(s)\n"
         << seconds(duration) << " segundo(s)\n";

    return 0;
}
