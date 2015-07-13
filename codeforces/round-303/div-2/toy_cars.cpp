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

    unsigned int cars;
    cin >> cars;

    vector<unsigned int> good_cars;

    for (unsigned int i {0}; i < cars; ++i)
    {
        bool is_good {true};

        for (unsigned int j {0}; j < cars; ++j)
        {
            unsigned int outcome;
            cin >> outcome;

            if (outcome == 1 || outcome == 3)
            {
                is_good = false;
            }
        }

        if (is_good)
        {
            good_cars.push_back(i + 1);
        }
    }

    cout << good_cars.size() << '\n';

    for (unsigned int i {0}; i < good_cars.size(); ++i)
    {
        cout << good_cars[i] << (i + 1 < good_cars.size() ? ' ' : '\n');
    }

    return 0;
}
