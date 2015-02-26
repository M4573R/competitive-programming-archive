#include <algorithm>
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

    unsigned int applications;
    unsigned int launches;
    unsigned int icons_per_screen;

    cin >> applications >> launches >> icons_per_screen;

    vector<unsigned int> icons(applications);
    vector<unsigned int> positions(applications + 1);

    for (unsigned int i {0}; i < applications; ++i)
    {
        cin >> icons[i];
        positions[icons[i]] = i;
    }

    unsigned long long gestures {0};

    for (unsigned int i {0}; i < launches; ++i)
    {
        unsigned int icon;
        cin >> icon;

        gestures += positions[icon] / icons_per_screen + 1;

        if (positions[icon] != 0)
        {
            unsigned int previous_icon {icons[positions[icon] - 1]};

            swap(icons[positions[icon]], icons[positions[previous_icon]]);
            swap(positions[icon], positions[previous_icon]);
        }
    }

    cout << gestures << '\n';

    return 0;
}
