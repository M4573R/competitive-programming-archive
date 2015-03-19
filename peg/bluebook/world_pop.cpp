#include <cmath>
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

    double rate;
    double population;

    unsigned int from;
    unsigned int to;

    cin >> rate >> from >> population >> to;

    for (unsigned int i {from}; i < to; ++i)
    {
        population += population * (rate / 100);
    }

    cout << llround(population) << '\n';

    return 0;
}
