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

    unsigned int computers;
    unsigned int cables;

    cin >> computers >> cables;

    unsigned int min_time {0};

    while ((1 << min_time) < cables && (1 << min_time) < computers)
    {
        ++min_time;
    }

    min_time += (computers - (1 << min_time) + cables - 1) / cables;

    cout << min_time << '\n';

    return 0;
}
