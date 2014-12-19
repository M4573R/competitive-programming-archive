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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int farmers;
        cin >> farmers;

        unsigned int premiums {0};

        for (unsigned int j {0}; j < farmers; ++j)
        {
            unsigned int farmyard_size;
            unsigned int animals;
            unsigned int environment_friendliness;

            cin >> farmyard_size >> animals >> environment_friendliness;

            premiums += farmyard_size * environment_friendliness;
        }

        cout << premiums << '\n';
    }

    return 0;
}
