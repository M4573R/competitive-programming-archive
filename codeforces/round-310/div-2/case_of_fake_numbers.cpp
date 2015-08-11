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

    unsigned int gears;
    unsigned int first_tooth;

    cin >> gears >> first_tooth;

    unsigned int rotations {gears - first_tooth};

    for (unsigned int i {1}; i < gears; ++i)
    {
        unsigned int tooth;
        cin >> tooth;

        if (i % 2)
        {
            tooth = (tooth + gears - rotations) % gears;
        }
        else
        {
            tooth = (tooth + rotations) % gears;
        }

        if (tooth != i)
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
