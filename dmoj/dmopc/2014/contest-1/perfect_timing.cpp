#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
bool is_leap(unsigned int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

inline
unsigned int month_days(unsigned int year, unsigned int month)
{
    static const vector<unsigned int> days {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    return days[month - 1] + (is_leap(year) && month == 2);
}

struct Time
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

    void advance()
    {
        ++second;
        normalize_second();
    }

private:
    void normalize_second()
    {
        if (second == 60)
        {
            second = 0;
            ++minute;
            normalize_minute();
        }
    }

    void normalize_minute()
    {
        if (minute == 60)
        {
            minute = 0;
            ++hour;
            normalize_hour();
        }
    }

    void normalize_hour()
    {
        if (hour == 24)
        {
            hour = 0;
            ++day;
            normalize_day();
        }
    }

    void normalize_day()
    {
        if (day > month_days(year, month))
        {
            day = 1;
            ++month;
            normalize_month();
        }
    }

    void normalize_month()
    {
        if (month > 12)
        {
            month = 1;
            ++year;
        }
    }
};

istream& operator>>(istream& in, Time& time)
{
    char delimiter;

    in >> time.year   >> delimiter
       >> time.month  >> delimiter
       >> time.day    >> delimiter
       >> time.hour   >> delimiter
       >> time.minute >> delimiter
       >> time.second;

    return in;
}

ostream& operator<<(ostream& out, const Time& time)
{
    out << setfill('0')
        << setw(4) << time.year   << ':'
        << setw(2) << time.month  << ':'
        << setw(2) << time.day    << ':'
        << setw(2) << time.hour   << ':'
        << setw(2) << time.minute << ':'
        << setw(2) << time.second << '\n';

    return out;
}

int main()
{
    use_io_optimizations();

    int current_x;
    int current_y;

    cin >> current_x >> current_y;

    int target_x;
    int target_y;

    cin >> target_x >> target_y;

    Time current;
    cin >> current;

    unsigned int till_arrival = (abs(current_x - target_x) +
                                 abs(current_y - target_y));

    for (unsigned int i {0}; i < till_arrival; ++i)
    {
        current.advance();
    }

    cout << current << '\n';

    return 0;
}
