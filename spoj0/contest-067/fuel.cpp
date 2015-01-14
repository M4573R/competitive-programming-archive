#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int routes_count(int gas_stations, int tank_capacity, const vector<int>& locations)
{
    vector<int> computed(gas_stations + 2);
    computed.back() = 1;

    for (int i = gas_stations; i >= 0; --i)
    {
        int routes = 0;

        for (int j = i + 1; j <= gas_stations + 1; ++j)
        {
            if (locations[j] - locations[i] > tank_capacity)
            {
                break;
            }

            routes = (routes + computed[j]) % mod;
        }

        computed[i] = routes;
    }

    return computed.front();
}

int main()
{
    use_io_optimizations();

    int test_cases;
    cin >> test_cases;

    for (int test = 0; test < test_cases; ++test)
    {
        int gas_stations;
        int target_location;
        int tank_capacity;

        cin >> gas_stations >> target_location >> tank_capacity;

        vector<int> locations(gas_stations + 2);

        for (int i = 1; i <= gas_stations; ++i)
        {
            cin >> locations[i];
        }

        locations.back() = target_location;

        cout << routes_count(gas_stations, tank_capacity, locations) << '\n';
    }

    return 0;
}
