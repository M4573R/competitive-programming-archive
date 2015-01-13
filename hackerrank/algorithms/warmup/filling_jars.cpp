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

    unsigned int jars;
    unsigned int operations;

    cin >> jars >> operations;

    long long total_candies {0};

    for (unsigned int i {0}; i < operations; ++i)
    {
        long long from;
        long long to;
        long long candies;

        cin >> from >> to >> candies;

        total_candies += (to - from + 1) * candies;
    }

    cout << total_candies / jars << '\n';

    return 0;
}
