#include <iostream>

using namespace std;

constexpr unsigned int problems              {12};
constexpr unsigned int one_hour              {60};
constexpr unsigned int contest_duration      {5 * one_hour};
constexpr unsigned int time_per_left_problem {45};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int solved_problems;
    cin >> solved_problems;

    unsigned int left_problems {problems - solved_problems};
    unsigned int left_time     {contest_duration - one_hour};
    unsigned int needed_time   {left_problems * time_per_left_problem};

    cout << (needed_time <= left_time ? "YES" : "NO") << '\n';

    return 0;
}
