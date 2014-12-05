/*
    ID:   gsshopo1
    PROG: friday
    LANG: C++11
*/

#include <fstream>
#include <map>
#include <vector>

using namespace std;

class Weekday
{
public:
    static const Weekday Monday;
    static const Weekday Tuesday;
    static const Weekday Wednesday;
    static const Weekday Thursday;
    static const Weekday Friday;
    static const Weekday Saturday;
    static const Weekday Sunday;

    static const unsigned int days_in_week;

    bool operator<(const Weekday& other) const
    {
        return day < other.day;
    }

    Weekday& operator+=(unsigned int days)
    {
        day = (day + days) % days_in_week;

        return *this;
    }

private:
    unsigned int day;

    Weekday(unsigned int day):
        day(day)
    { }
};

const Weekday Weekday::Monday    {0};
const Weekday Weekday::Tuesday   {1};
const Weekday Weekday::Wednesday {2};
const Weekday Weekday::Thursday  {3};
const Weekday Weekday::Friday    {4};
const Weekday Weekday::Saturday  {5};
const Weekday Weekday::Sunday    {6};

const unsigned int Weekday::days_in_week {7};

const     Weekday      start_weekday {Weekday::Saturday};
constexpr unsigned int start_month   {1};
constexpr unsigned int start_year    {1900};

inline bool is_leap(unsigned int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

inline unsigned int month_days(unsigned int month, unsigned int year)
{
    static const vector<unsigned int> days {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    return days[month - 1] + (month == 2 ? is_leap(year) : 0);
}

int main()
{
    ifstream fin  {"friday.in"};
    ofstream fout {"friday.out"};

    unsigned int period;
    fin >> period;

    Weekday current_day {start_weekday};
    map<Weekday, unsigned int> frequencies;

    for (unsigned int year {start_year}; year < start_year + period; ++year)
    {
        for (unsigned int month {start_month}; month <= 12; ++month)
        {
            ++frequencies[current_day];
            current_day += month_days(month, year);
        }
    }

    fout << frequencies[Weekday::Saturday]  << ' '
         << frequencies[Weekday::Sunday]    << ' '
         << frequencies[Weekday::Monday]    << ' '
         << frequencies[Weekday::Tuesday]   << ' '
         << frequencies[Weekday::Wednesday] << ' '
         << frequencies[Weekday::Thursday]  << ' '
         << frequencies[Weekday::Friday]    << '\n';

    return 0;
}
