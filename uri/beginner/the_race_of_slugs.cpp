#include <algorithm>
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

    for (unsigned int slugs; cin >> slugs; )
    {
        unsigned int max_speed {0};

        for (unsigned int i {0}; i < slugs; ++i)
        {
            unsigned int speed;
            cin >> speed;

            max_speed = max(max_speed, speed);
        }

        cout << min(max_speed / 10 + 1, 3u) << '\n';
    }

    return 0;
}
