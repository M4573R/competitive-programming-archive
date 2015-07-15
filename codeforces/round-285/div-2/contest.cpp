#include <algorithm>
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

    unsigned int a_points;
    unsigned int b_points;

    cin >> a_points >> b_points;

    unsigned int a_time;
    unsigned int b_time;

    cin >> a_time >> b_time;

    unsigned int a_score {max(3 * a_points / 10,
                              a_points - a_points / 250 * a_time)};

    unsigned int b_score {max(3 * b_points / 10,
                              b_points - b_points / 250 * b_time)};

    cout << (a_score > b_score ? "Misha":
             a_score < b_score ? "Vasya":
                                 "Tie")
         << '\n';

    return 0;
}
