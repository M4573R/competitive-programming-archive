#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

constexpr unsigned int few_lower_bound     {1};
constexpr unsigned int several_lower_bound {5};
constexpr unsigned int pack_lower_bound    {10};
constexpr unsigned int lots_lower_bound    {20};
constexpr unsigned int horde_lower_bound   {50};
constexpr unsigned int throng_lower_bound  {100};
constexpr unsigned int swarm_lower_bound   {250};
constexpr unsigned int zounds_lower_bound  {500};
constexpr unsigned int legion_lower_bound  {1000};

int main()
{
    use_io_optimizations();

    unsigned int number;
    cin >> number;

    if (number >= legion_lower_bound)
    {
        cout << "legion";
    }
    else if (number >= zounds_lower_bound)
    {
        cout << "zounds";
    }
    else if (number >= swarm_lower_bound)
    {
        cout << "swarm";
    }
    else if (number >= throng_lower_bound)
    {
        cout << "throng";
    }
    else if (number >= horde_lower_bound)
    {
        cout << "horde";
    }
    else if (number >= lots_lower_bound)
    {
        cout << "lots";
    }
    else if (number >= pack_lower_bound)
    {
        cout << "pack";
    }
    else if (number >= several_lower_bound)
    {
        cout << "several";
    }
    else if (number >= few_lower_bound)
    {
        cout << "few";
    }

    cout << '\n';

    return 0;
}
