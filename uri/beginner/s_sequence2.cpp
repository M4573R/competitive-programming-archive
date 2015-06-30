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

    for (unsigned int i {1}, j {1}; i <= 39; i += 2, j *= 2)
    {
        sum += static_cast<double>(i) / j;
    }

    cout << sum << '\n';

    return 0;
}
