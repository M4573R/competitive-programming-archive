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

    unsigned int stations_count;
    cin >> stations_count;
    cin.ignore();

    vector<string> stations(stations_count);

    for (auto& station : stations)
    {
        getline(cin, station);
    }

    bool is_valid {false};

    for (unsigned int i {1}; i < stations_count - 1 && !is_valid; ++i)
    {
        if (stations[i] == "Bessarion")
        {
            if (stations[i - 1] == "Leslie" && stations[i + 1] == "Bayview")
            {
                is_valid = true;
            }

            if (stations[i - 1] == "Bayview" && stations[i + 1] == "Leslie")
            {
                is_valid = true;
            }
        }
    }

    cout << (is_valid ? 'Y' : 'N') << '\n';

    return 0;
}
