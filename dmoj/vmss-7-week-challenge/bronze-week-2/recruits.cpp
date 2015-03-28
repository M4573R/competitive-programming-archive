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

    vector<unsigned int> heights(soldiers + 2);

    for (unsigned int i {1}; i <= soldiers; ++i)
    {
        cin >> heights[i];
    }

    unsigned int ugly_count {0};

    for (unsigned int i {1}; i <= soldiers; ++i)
    {
        if (heights[i - 1] <= 41 && heights[i] <= 41 && heights[i + 1] <= 41)
        {
            ++ugly_count;
        }
    }

    cout << ugly_count << '\n';

    return 0;
}
