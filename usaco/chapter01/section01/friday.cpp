/*
    ID:   gsshopo1
    PROG: friday
    LANG: C++11
*/

#include <fstream>
#include <map>
#include <set>

using namespace std;

enum class Weekday
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

Weekday& operator++(Weekday& weekday)
{
    switch (weekday)
    {
    case Weekday::Monday:
        weekday = Weekday::Tuesday;
        break;

    case Weekday::Tuesday:
        weekday = Weekday::Wednesday;
        break;

    case Weekday::Wednesday:
        weekday = Weekday::Thursday;
        break;

    case Weekday::Thursday:
        weekday = Weekday::Friday;
        break;

    case Weekday::Friday:
        weekday = Weekday::Saturday;
        break;

    case Weekday::Saturday:
        weekday = Weekday::Sunday;
        break;

    case Weekday::Sunday:
        weekday = Weekday::Monday;
        break;
    }
}

constexpr unsigned int start_day     {1};
constexpr unsigned int start_month   {1};
constexpr unsigned int start_year    {1900};
constexpr Weekday      start_weekday {Weekday::Monday};

struct Date
{
    Date(unsigned int day   = start_day,
         unsigned int month = start_month,
         unsigned int year  = start_year,
         Weekday weekday    = start_weekday):
        day(day),
        month(month),
        year(year),
        weekday(weekday)
    { }

    bool is_leap()
    {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    Date& operator++()
    {
        ++day;
        ++weekday;

        if ((day == 29 && month == 2 && !is_leap())       ||
            (day == 30 && month == 2 &&  is_leap())       ||
            (day == 31 && thirty_day_months.count(month)) ||
            (day == 32))
        {
            day = 1;
            ++month;

            if (month == 13)
            {
                month = 1;
                ++year;
            }
        }

        return *this;
    }

    unsigned int day;
    unsigned int month;
    unsigned int year;

    Weekday weekday;

    static const set<unsigned int> thirty_day_months;
};

const set<unsigned int> Date::thirty_day_months {4, 6, 9, 11};

int main()
{
    ifstream fin  {"friday.in"};
    ofstream fout {"friday.out"};

    unsigned int period;
    fin >> period;

    map<Weekday, unsigned int> frequencies;

    for (Date date; date.year < start_year + period; ++date)
    {
        if (date.day == 13)
        {
            ++frequencies[date.weekday];
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
