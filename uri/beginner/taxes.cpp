#include <algorithm>
#include <iomanip>
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

    cout << fixed << setprecision(2);

    double salary;
    cin >> salary;

    double taxes {0};

    if (salary > 2000)
    {
        taxes += min(salary - 2000, 1000.0) * 0.08;
    }

    if (salary > 3000)
    {
        taxes += min(salary - 3000, 1500.0) * 0.18;
    }

    if (salary > 4500)
    {
        taxes += (salary - 4500) * 0.28;
    }

    if (taxes)
    {
        cout << "R$ " << taxes;
    }
    else
    {
        cout << "Isento";
    }

    cout << '\n';

    return 0;
}
