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

    cout << fixed << setprecision(9);

    int       a;
    long      b;
    long long c;
    char      d;
    float     e;
    double    f;

    cin >> a >> b >> c >> d >> e >> f;

    cout << a << '\n'
         << b << '\n'
         << c << '\n'
         << d << '\n'
         << e << '\n'
         << f << '\n';

    return 0;
}
