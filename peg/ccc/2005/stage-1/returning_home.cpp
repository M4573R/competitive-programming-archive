#include <iostream>
#include <string>
#include <vector>

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

    vector<string> directions;
    vector<string> locations;

    for (string direction, location; cin >> direction >> location; )
    {
        directions.push_back(direction == "L" ? "RIGHT" : "LEFT");

        if (location != "SCHOOL")
        {
            locations.push_back(location);
        }
    }

    for (auto i = directions.size() - 1; i > 0; --i)
    {
        cout << "Turn " << directions[i]    << ' '
             << "onto " << locations[i - 1] << " street.\n";
    }

    cout << "Turn " << directions.front() << " into your HOME.\n";

    return 0;
}
