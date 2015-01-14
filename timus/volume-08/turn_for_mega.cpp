#include <algorithm>
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

    unsigned int outflow_per_minute;
    unsigned int passed_minutes;

    cin >> outflow_per_minute >> passed_minutes;

    unsigned int cars_in_traffic_jam {0};

    for (unsigned int i {0}; i < passed_minutes; ++i)
    {
        unsigned int approaching_cars;
        cin >> approaching_cars;

        cars_in_traffic_jam += approaching_cars;
        cars_in_traffic_jam -= min(cars_in_traffic_jam, outflow_per_minute);
    }

    cout << cars_in_traffic_jam << '\n';

    return 0;
}
