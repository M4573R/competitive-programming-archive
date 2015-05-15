#include <cmath>
#include <iostream>

using namespace std;

constexpr unsigned int total_bets {1000};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    double a;
    double b;
    double c;

    cin >> a >> b >> c;

    cout << round(total_bets * a * b * c / (a * b + a * c + b * c)) << '\n';

    return 0;
}
