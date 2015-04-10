#include <iomanip>
#include <iostream>

using namespace std;

constexpr double pi {3.14159};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(3);

    double first;
    double second;
    double third;

    cin >> first >> second >> third;

    cout << "TRIANGULO: " << first * third / 2            << '\n'
         << "CIRCULO: "   << pi * third * third           << '\n'
         << "TRAPEZIO: "  << (first + second) / 2 * third << '\n'
         << "QUADRADO: "  << second * second              << '\n'
         << "RETANGULO: " << first  * second              << '\n';

    return 0;
}
