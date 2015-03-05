#include <iostream>
#include <vector>

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

    unsigned int soldiers;
    cin >> soldiers;

    vector<unsigned> heights(soldiers);

    for (auto& height : heights)
    {
        cin >> height;
    }

    unsigned int min {0};
    unsigned int max {0};

    for (unsigned int i {1}; i < soldiers; ++i)
    {
        if (heights[i] > heights[max])
        {
            max = i;
        }

        if (heights[i] <= heights[min])
        {
            min = i;
        }
    }

    cout << max + (soldiers - 1 - min) - (max > min) << '\n';

    return 0;
}
