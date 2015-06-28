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

    cout << fixed << setprecision(1);

    double a;
    double b;
    double c;

    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a)
    {
        cout << "Perimetro = " << a + b + c;
    }
    else
    {
        cout << "Area = " << (a + b) * c / 2;
    }

    cout << '\n';

    return 0;
}
