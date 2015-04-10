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

    double first;
    double second;
    double third;

    cin >> first >> second >> third;

    cout << "MEDIA = " << (first * 2 + second * 3 + third * 5) / 10 << '\n';

    return 0;
}
