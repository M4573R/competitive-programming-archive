#include <iostream>
#include <string>

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
    string path;

    cin >> height >> path;

    unsigned int nodes    {1u << (height + 1)};
    unsigned int position {1};

    for (auto direction : path)
    {
        position *= 2;

        if (direction == 'R')
        {
            ++position;
        }
    }

    cout << nodes - position << '\n';

    return 0;
}
