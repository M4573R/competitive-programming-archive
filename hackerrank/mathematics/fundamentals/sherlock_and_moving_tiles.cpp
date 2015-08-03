#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>

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

    cout << fixed << setprecision(9);

    unsigned int side;
    unsigned int first_velocity;
    unsigned int second_velocity;

    cin >> side >> first_velocity >> second_velocity;

    if (first_velocity < second_velocity)
    {
        swap(first_velocity, second_velocity);
    }

    double velocity {(first_velocity - second_velocity) / sqrt(2)};

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned long long area;
        cin >> area;

        cout << (side - sqrt(area)) / velocity << '\n';
    }

    return 0;
}
