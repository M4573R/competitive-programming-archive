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

    unsigned int sections;
    cin >> sections;

    unsigned int force_a;
    unsigned int force_b;
    unsigned int force_c;

    cin >> force_a >> force_b >> force_c;

    unsigned int entrance_force  {force_a + force_b + force_c};
    unsigned int entrance_middle {2};

    for (unsigned int i {3}; i < sections; ++i)
    {
        force_a = force_b;
        force_b = force_c;

        cin >> force_c;

        if (force_a + force_b + force_c > entrance_force)
        {
            entrance_force  = force_a + force_b + force_c;
            entrance_middle = {i};
        }
    }

    cout << entrance_force << ' ' << entrance_middle << '\n';

    return 0;
}
