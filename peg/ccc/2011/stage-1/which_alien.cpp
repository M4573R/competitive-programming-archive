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

    unsigned int antenna;
    unsigned int eyes;

    cin >> antenna >> eyes;

    if (antenna >= 3 && eyes <= 4)
    {
        cout << "TroyMartian\n";
    }

    if (antenna <= 6 && eyes >= 2)
    {
        cout << "VladSaturnian\n";
    }

    if (antenna <= 2 && eyes <= 3)
    {
        cout << "GraemeMercurian\n";
    }

    return 0;
}
