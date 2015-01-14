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

    unsigned int tram_stops;
    cin >> tram_stops;

    unsigned int passengers_in_tram    {0};
    unsigned int tram_minimum_capacity {0};

    for (unsigned int i {0}; i < tram_stops; ++i)
    {
        unsigned int exiting_passengers;
        unsigned int entering_passengers;

        cin >> exiting_passengers >> entering_passengers;

        passengers_in_tram += - exiting_passengers + entering_passengers;

        if (passengers_in_tram > tram_minimum_capacity)
        {
            tram_minimum_capacity = passengers_in_tram;
        }
    }

    cout << tram_minimum_capacity << '\n';

    return 0;
}
