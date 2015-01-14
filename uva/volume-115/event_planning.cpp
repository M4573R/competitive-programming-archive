#include <algorithm>
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

    unsigned int participants;
    unsigned int budget;
    unsigned int hotels;
    unsigned int weeks;

    while (cin >> participants >> budget >> hotels >> weeks)
    {
        unsigned int total_cost {budget + 1};

        for (unsigned int i {0}; i < hotels; ++i)
        {
            unsigned int price_per_person;
            cin >> price_per_person;

            for (unsigned int j {0}; j < weeks; ++j)
            {
                unsigned int available_beds;
                cin >> available_beds;

                if (available_beds >= participants)
                {
                    total_cost = min(total_cost, participants * price_per_person);
                }
            }
        }

        if (total_cost > budget)
        {
            cout << "stay home";
        }
        else
        {
            cout << total_cost;
        }

        cout << '\n';
    }

    return 0;
}
