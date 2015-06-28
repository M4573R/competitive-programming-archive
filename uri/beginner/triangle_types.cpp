#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void sort(double& a, double& b, double& c)
{
    if (a < b)
    {
        swap(a, b);
    }

    if (a < c)
    {
        swap(a, c);
    }

    if (b < c)
    {
        swap(b, c);
    }
}

int main()
{
    use_io_optimizations();

    double a;
    double b;
    double c;

    cin >> a >> b >> c;

    sort(a, b, c);

    if (a >= b + c)
    {
        cout << "NAO FORMA TRIANGULO\n";
        return 0;
    }

    if (a * a == b * b + c * c)
    {
        cout << "TRIANGULO RETANGULO\n";
    }
    else if (a * a > b * b + c * c)
    {
        cout << "TRIANGULO OBTUSANGULO\n";
    }
    else
    {
        cout << "TRIANGULO ACUTANGULO\n";
    }

    if (a == b && b == c)
    {
        cout << "TRIANGULO EQUILATERO\n";
    }
    else if (a == b || a == c || b == c)
    {
        cout << "TRIANGULO ISOSCELES\n";
    }

    return 0;
}
