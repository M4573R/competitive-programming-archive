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

    unsigned int rooms;
    cin >> rooms;

    unsigned int eligible_rooms {0};

    for (unsigned int i {0}; i < rooms; ++i)
    {
        unsigned int inhabitants;
        unsigned int capacity;

        cin >> inhabitants >> capacity;

        if (inhabitants + 2 <= capacity)
        {
            ++eligible_rooms;
        }
    }

    cout << eligible_rooms << '\n';

    return 0;
}
