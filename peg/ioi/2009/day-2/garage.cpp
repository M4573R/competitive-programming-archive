#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using MinHeap = priority_queue<
                    unsigned int,
                    vector<unsigned int>,
                    greater<unsigned int>
                >;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(unsigned int& spots,
                unsigned int& cars,
                vector<unsigned int>& rates,
                vector<unsigned int>& weights)
{
    cin >> spots >> cars;

    rates.resize(spots + 1);

    for (unsigned int i {1}; i <= spots; ++i)
    {
        cin >> rates[i];
    }

    weights.resize(cars + 1);

    for (unsigned int i {1}; i <= cars; ++i)
    {
        cin >> weights[i];
    }
}

unsigned int calculate_profit(unsigned int spots,
                              unsigned int cars,
                              const vector<unsigned int>& rates,
                              const vector<unsigned int>& weights)
{
    queue<unsigned int>  waiting;
    vector<unsigned int> car_spots(cars + 1);
    MinHeap              free_spots;

    for (unsigned int i {1}; i <= spots; ++i)
    {
        free_spots.push(i);
    }

    unsigned int profit {0};

    for (unsigned int i {0}; i < 2 * cars; ++i)
    {
        int event;
        cin >> event;

        if (event < 0)
        {
            free_spots.push(car_spots[-event]);
        }
        else
        {
            waiting.push(event);
        }

        if (!waiting.empty() && !free_spots.empty())
        {
            unsigned int car  {waiting.front()};
            unsigned int spot {free_spots.top()};

            waiting.pop();
            free_spots.pop();

            car_spots[car] = spot;
            profit += weights[car] * rates[spot];
        }
    }

    return profit;
}

int main()
{
    use_io_optimizations();

    unsigned int spots;
    unsigned int cars;

    vector<unsigned int> rates;
    vector<unsigned int> weights;

    read_input(spots, cars, rates, weights);

    cout << calculate_profit(spots, cars, rates, weights) << '\n';

    return 0;
}
