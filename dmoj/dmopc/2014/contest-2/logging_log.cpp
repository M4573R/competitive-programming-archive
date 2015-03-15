#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int days;
    cin >> days;

    for (unsigned int day {1}; day <= days; ++day)
    {
        unsigned int trees;
        cin >> trees;

        unsigned int day_mass {0};

        for (unsigned int tree {1}; tree <= trees; ++tree)
        {
            unsigned int tree_mass;
            cin >> tree_mass;

            day_mass += tree_mass;
        }

        if (day_mass == 0)
        {
            cout << "Weekend";
        }
        else
        {
            cout << "Day " << day << ": " << day_mass;
        }

        cout << '\n';
    }

    return 0;
}
