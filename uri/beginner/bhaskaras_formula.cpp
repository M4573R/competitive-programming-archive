#include <cmath>
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

    cout << fixed << setprecision(5);

    double a;
    double b;
    double c;

    cin >> a >> b >> c;

    double discriminant {b * b - 4 * a * c};

    if (a == 0 || discriminant < 0)
    {
        cout << "Impossivel calcular\n";
    }
    else
    {
        cout << "R1 = " << (-b + sqrt(discriminant)) / (2 * a) << '\n'
             << "R2 = " << (-b - sqrt(discriminant)) / (2 * a) << '\n';
    }

    return 0;
}
