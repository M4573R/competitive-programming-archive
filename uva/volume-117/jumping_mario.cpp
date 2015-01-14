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
        unsigned int walls;
        cin >> walls;

        unsigned int current_wall;
        cin >> current_wall;

        unsigned int high_jumps {0};
        unsigned int low_jumps  {0};

        for (unsigned int j {1}; j < walls; ++j)
        {
            unsigned int next_wall;
            cin >> next_wall;

            if (current_wall < next_wall)
            {
                ++high_jumps;
            }
            else if (current_wall > next_wall)
            {
                ++low_jumps;
            }

            current_wall = next_wall;
        }

        cout << "Case " << i + 1 << ": " << high_jumps << ' ' << low_jumps << '\n';
    }

    return 0;
}
