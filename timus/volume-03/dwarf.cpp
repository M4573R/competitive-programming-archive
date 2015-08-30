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

    double gold;
    double lower_bound;
    double percentage;

    cin >> gold >> lower_bound >> percentage;

    unsigned int years {0};

    while (gold > lower_bound)
    {
        gold -= gold * percentage / 100;
        ++years;
    }

    cout << years << '\n';

    return 0;
}
