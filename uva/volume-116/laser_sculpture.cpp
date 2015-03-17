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

    unsigned int height;
    unsigned int width;

    while (cin >> height && height != 0 && cin >> width)
    {
        unsigned int current_height {height};
        unsigned int laser_uses     {0};

        for (unsigned int i {0}; i < width; ++i)
        {
            unsigned int block_height;
            cin >> block_height;

            if (block_height < current_height)
            {
                laser_uses += current_height - block_height;
            }

            current_height = block_height;
        }

        cout << laser_uses << '\n';
    }

    return 0;
}
