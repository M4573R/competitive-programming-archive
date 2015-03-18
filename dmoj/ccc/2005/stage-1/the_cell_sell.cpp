#include <algorithm>
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

    int daytime;
    int evening;
    int weekend;

    cin >> daytime >> evening >> weekend;

    double a_cost {
        max(0, daytime - 100) * 0.25 + evening * 0.15 + weekend * 0.20
    };

    double b_cost {
        max(0, daytime - 250) * 0.45 + evening * 0.35 + weekend * 0.25
    };

    cout << "Plan A costs " << a_cost << '\n';
    cout << "Plan B costs " << b_cost << '\n';

    cout << (a_cost < b_cost ? "Plan A is cheapest." :
             b_cost < a_cost ? "Plan B is cheapest." :
                               "Plan A and B are the same price.") << '\n';

    return 0;
}
