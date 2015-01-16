#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(6);

    unsigned int undines;
    unsigned int sail_time;
    unsigned int anna_enter_time;

    cin >> undines >> sail_time >> anna_enter_time;

    for (unsigned int i {0}; i < undines; ++i)
    {
        unsigned int undine_enter_time;
        cin >> undine_enter_time;

        unsigned int max_enter_time {max(undine_enter_time, anna_enter_time)};
        unsigned int min_enter_time {min(undine_enter_time, anna_enter_time)};

        cout << (sail_time + max_enter_time + min_enter_time) / 2.0 << '\n';
    }

    return 0;
}
