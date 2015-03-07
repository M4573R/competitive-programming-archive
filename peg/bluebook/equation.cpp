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

    double a;
    double b;

    cin >> a >> b;

    if (a == 0 && b == 0)
    {
        cout << "indeterminate";
    }
    else if (a == 0 && b != 0)
    {
        cout << "undefined";
    }
    else
    {
        cout << -b / a;
    }

    cout << '\n';

    return 0;
}
