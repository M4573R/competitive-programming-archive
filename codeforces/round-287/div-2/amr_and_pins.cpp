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

    unsigned int radius;
    cin >> radius;

    long long source_x;
    long long source_y;

    long long destination_x;
    long long destination_y;

    cin >> source_x      >> source_y
        >> destination_x >> destination_y;

    double distance {
        sqrt((source_x - destination_x) * (source_x - destination_x) +
             (source_y - destination_y) * (source_y - destination_y))
    };

    cout << ceil(distance / (2 * radius)) << '\n';

    return 0;
}
