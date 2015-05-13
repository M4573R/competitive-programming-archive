#include <algorithm>
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

    unsigned int blue_reagents;
    unsigned int red_reagents;
    unsigned int yellow_reagents;

    cin >> blue_reagents >> red_reagents >> yellow_reagents;

    unsigned int colors;
    cin >> colors;

    bool is_blue_needed   {false};
    bool is_red_needed    {false};
    bool is_yellow_needed {false};

    for (unsigned int i {0}; i < colors; ++i)
    {
        string color;
        cin >> color;

        if (color == "Blue")
        {
            is_blue_needed = true;
        }
        else if (color == "Red")
        {
            is_red_needed = true;
        }
        else
        {
            is_yellow_needed = true;
        }
    }

    cout << max(1u, blue_reagents   * is_blue_needed) *
            max(1u, red_reagents    * is_red_needed)  *
            max(1u, yellow_reagents * is_yellow_needed) << '\n';

    return 0;
}
