#include <iomanip>
#include <iostream>
#include <string>

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

    string name;
    double salary;
    double sold;

    cin >> name >> salary >> sold;

    cout << "TOTAL = R$ " << salary + sold * 0.15 << '\n';

    return 0;
}
