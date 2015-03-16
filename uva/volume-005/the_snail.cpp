#include <algorithm>
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
    unsigned int climb;
    unsigned int slide;
    unsigned int factor;

    while (cin >> height >> climb >> slide >> factor && height != 0)
    {
        double position       {0};
        double fatigue        {factor / 100.0 * climb};
        double previous_climb {climb};

        for (unsigned int day {1}; true; ++day)
        {
            position       += max(0.0, previous_climb);
            previous_climb -= fatigue;

            if (position > height)
            {
                cout << "success on day " << day << '\n';
                break;
            }

            position -= slide;

            if (position < 0)
            {
                cout << "failure on day " << day << '\n';
                break;
            }
        }
    }

    return 0;
}
