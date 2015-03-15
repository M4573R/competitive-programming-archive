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

    unsigned int antennas;
    unsigned int eyes;

    cin >> antennas >> eyes;

    if (antennas >= 3 && eyes <= 4)
    {
        cout << "TroyMartian\n";
    }

    if (antennas <= 6 && eyes >= 2)
    {
        cout << "VladSaturnian\n";
    }

    if (antennas <= 2 && eyes <= 3)
    {
        cout << "GraemeMercurian\n";
    }

    return 0;
}
