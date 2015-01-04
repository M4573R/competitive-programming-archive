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

    unsigned int blocks_count;
    unsigned int block_size;

    cin >> blocks_count >> block_size;

    unsigned int unused_balls {0};
    unsigned int alive_droids {0};

    for (unsigned int i {0}; i < blocks_count; ++i)
    {
        unsigned int balls_in_truck;
        cin >> balls_in_truck;

        if (balls_in_truck > block_size)
        {
            unused_balls += balls_in_truck - block_size;
        }
        else
        {
            alive_droids += block_size - balls_in_truck;
        }
    }

    cout << unused_balls << ' ' << alive_droids << '\n';

    return 0;
}
