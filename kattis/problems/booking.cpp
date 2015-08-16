#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Event
{
    time_t time_stamp;
    bool is_departure;
};

bool operator<(const Event& left, const Event& right)
{
    if (left.time_stamp < right.time_stamp)
    {
        return true;
    }

    if (left.time_stamp > right.time_stamp)
    {
        return false;
    }

    return left.is_departure && !right.is_departure;
}

istream& operator>>(istream& in, Event& event)
{
    char delimiter;
    tm date {0};

    in >> date.tm_year >> delimiter
       >> date.tm_mon  >> delimiter
       >> date.tm_mday
       >> date.tm_hour >> delimiter
       >> date.tm_min;

    date.tm_year -= 1900;
    date.tm_mon  -= 1;

    event.time_stamp = mktime(&date);

    return in;
}

void read_input(unsigned int& bookings,
                unsigned int& cleaning_time,
                vector<Event>& events)
{
    cin >> bookings >> cleaning_time;

    events.resize(2 * bookings);

    for (unsigned int i {0}; i < 2 * bookings; i += 2)
    {
        string code;
        cin >> code >> events[i] >> events[i + 1];

        events[i + 1].time_stamp  += 60 * cleaning_time;
        events[i + 1].is_departure = true;
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int bookings;
        unsigned int cleaning_time;

        vector<Event> events;

        read_input(bookings, cleaning_time, events);
        sort(events.begin(), events.end());

        unsigned int maximum {0};
        unsigned int current {0};

        for (const auto& event : events)
        {
            if (event.is_departure)
            {
                --current;
            }
            else
            {
                ++current;
            }

            maximum  = max(maximum, current);
        }

        cout << maximum << '\n';
    }

    return 0;
}
