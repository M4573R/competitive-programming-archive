#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

constexpr double pi {acos(-1)};

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

    for (unsigned int length; cin >> length && length > 0; )
    {
        cout << (length * length) / (2 * pi) << '\n';
    }

    return 0;
}
