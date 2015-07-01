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

    cout << fixed << setprecision(4);

    double current;
    cin >> current;

    for (unsigned int i {0}; i < 100; ++i)
    {
        cout << "N[" << i << "] = " << current << '\n';
        current /= 2;
    }

    return 0;
}
