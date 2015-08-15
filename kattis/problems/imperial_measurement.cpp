#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<string, unsigned int> thous {
    {"thou",           1}, {"th",          1},
    {"inch",        1000}, {"in",       1000},
    {"foot",       12000}, {"ft",      12000},
    {"yard",       36000}, {"yd",      36000},
    {"chain",     792000}, {"ch",     792000},
    {"furlong",  7920000}, {"fur",   7920000},
    {"mile",    63360000}, {"mi",   63360000},
    {"league", 190080000}, {"lea", 190080000}
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(12);

    double units;

    string from;
    string to;
    string delimiter;

    cin >> units >> from >> delimiter >> to;

    cout << units * thous.at(from) / thous.at(to) << '\n';

    return 0;
}
