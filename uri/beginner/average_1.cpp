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

    double first;
    double second;

    cin >> first >> second;

    cout << "MEDIA = " << (first * 3.5 + second * 7.5) / 11 << '\n';

    return 0;
}
