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

    int x {0};
    int y {0};

    unsigned int moves;
    cin >> moves;

    for (unsigned int i {0}; i < moves; ++i)
    {
        string direction;
        unsigned int distance;

        cin >> direction >> distance;

        if (direction == "North")
        {
            y += distance;
        }
        else if (direction == "South")
        {
            y -= distance;
        }
        else if (direction == "East")
        {
            x += distance;
        }
        else if (direction == "West")
        {
            x -= distance;
        }
    }

    cout << x << ' ' << y << '\n';

    return 0;
}
