#include <algorithm>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int creatures;
        cin >> creatures;

        unsigned int required_speed {0};

        for (unsigned int j {0}; j < creatures; ++j)
        {
            unsigned int creature_speed;
            cin >> creature_speed;

            required_speed = max(required_speed, creature_speed);
        }

        cout << "Case " << i + 1 << ": " << required_speed << '\n';
    }

    return 0;
}
