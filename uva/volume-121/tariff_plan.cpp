#include <iostream>

using namespace std;

constexpr unsigned int mile_time  {30};
constexpr unsigned int juice_time {60};

constexpr unsigned int mile_rate  {10};
constexpr unsigned int juice_rate {15};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int calls;
        cin >> calls;

        unsigned int mile_cost  {0};
        unsigned int juice_cost {0};

        for (unsigned int i {0}; i < calls; ++i)
        {
            unsigned int duration;
            cin >> duration;

            mile_cost  += (duration / mile_time  + 1) * mile_rate;
            juice_cost += (duration / juice_time + 1) * juice_rate;
        }

        cout << "Case " << test << ": ";

        if (mile_cost < juice_cost)
        {
            cout << "Mile " << mile_cost;
        }
        else if (juice_cost < mile_cost)
        {
            cout << "Juice " << juice_cost;
        }
        else
        {
            cout << "Mile Juice " << mile_cost;
        }

        cout << '\n';
    }

    return 0;
}
