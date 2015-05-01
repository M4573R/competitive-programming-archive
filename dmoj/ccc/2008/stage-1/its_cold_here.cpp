#include <iostream>
#include <string>

using namespace std;

constexpr int highest_temperature {200};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string coldest_city;
    int lowest_temperature {highest_temperature};

    string city;
    int temperature;

    while (cin >> city >> temperature)
    {
        if (temperature < lowest_temperature)
        {
            coldest_city       = city;
            lowest_temperature = temperature;
        }
    }

    cout << coldest_city << '\n';

    return 0;
}
