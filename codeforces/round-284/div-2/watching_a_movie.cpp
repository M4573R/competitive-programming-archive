#include <iostream>

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

    unsigned int moments;
    unsigned int skip;

    cin >> moments >> skip;

    unsigned int min_minutes    {0};
    unsigned int current_minute {1};

    for (unsigned int i {0}; i < moments; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        min_minutes    += to - (from - (from - current_minute) % skip) + 1;
        current_minute  = to + 1;
    }

    cout << min_minutes << '\n';

    return 0;
}
