#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    int current_floor;
    cin >> current_floor;

    int floors_higher {1};

    while (to_string(current_floor + floors_higher).find('8') == string::npos)
    {
        ++floors_higher;
    }

    cout << floors_higher << '\n';

    return 0;
}
