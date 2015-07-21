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

    char delimiter;

    int current_hour;
    int current_minute;

    int sleep_hour;
    int sleep_minute;

    cin >> current_hour >> delimiter >> current_minute
        >> sleep_hour   >> delimiter >> sleep_minute;

    int start_time {
        60 * (current_hour - sleep_hour) + (current_minute - sleep_minute)
    };

    start_time = (start_time + 24 * 60) % (24 * 60);

    cout << setfill('0')
         << setw(2) << start_time / 60 << ':'
         << setw(2) << start_time % 60 << '\n';

    return 0;
}
