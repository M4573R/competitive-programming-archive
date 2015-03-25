#include <cmath>
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

    double base_length;
    double pyramid_height;

    cin >> base_length >> pyramid_height;

    cout << ceil(base_length * base_length * pyramid_height / 3) << '\n';

    return 0;
}
