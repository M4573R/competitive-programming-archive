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

    unsigned int griffy_height;
    cin >> griffy_height;

    unsigned int plushies;
    cin >> plushies;

    unsigned int plushies_in_the_way {0};

    for (unsigned int i {0}; i < plushies; ++i)
    {
        unsigned int height;
        cin >> height;

        if (height >= griffy_height)
        {
            ++plushies_in_the_way;
        }
    }

    cout << plushies_in_the_way << '\n';

    return 0;
}
