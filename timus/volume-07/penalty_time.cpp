#include <iostream>

using namespace std;

constexpr unsigned int problems       {10};
constexpr unsigned int reject_penalty {20};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int qxx_time;
    unsigned int zzz_time;

    cin >> qxx_time >> zzz_time;

    unsigned int penalty_time {0};

    for (unsigned int i {0}; i < problems; ++i)
    {
        unsigned int rejected_runs;
        cin >> rejected_runs;

        penalty_time += rejected_runs * reject_penalty;
    }

    if (zzz_time < qxx_time + penalty_time)
    {
        cout << "Dirty debug :(";
    }
    else
    {
        cout << "No chance.";
    }

    return 0;
}
