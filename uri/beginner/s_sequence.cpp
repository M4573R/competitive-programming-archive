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

    cout << fixed << setprecision(2);

    double sum {0};

    for (unsigned int i {1}; i <= 100; ++i)
    {
        sum += 1.0 / i;
    }

    cout << sum << '\n';

    return 0;
}
