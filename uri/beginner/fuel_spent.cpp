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

    cout << fixed << setprecision(3);

    unsigned int time;
    unsigned int speed;

    cin >> time >> speed;

    cout << time * speed / 12.0 << '\n';

    return 0;
}
