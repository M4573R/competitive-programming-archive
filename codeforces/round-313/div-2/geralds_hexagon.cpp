#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
unsigned int square(unsigned int number)
{
    return number * number;
}

int main()
{
    use_io_optimizations();

    vector<unsigned int> sides(6);

    for (auto& side : sides)
    {
        cin >> side;
    }

    unsigned int triangles {square(sides[0] + sides[1] + sides[2]) -
                            square(sides[0]) -
                            square(sides[2]) -
                            square(sides[4])};

    cout << triangles << '\n';

    return 0;
}
