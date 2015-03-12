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

    unsigned int winner_number {0};
    unsigned int winner_points {0};

    for (unsigned int i {1}; i <= 5; ++i)
    {
        unsigned int points {0};

        for (unsigned int j {1}; j <= 4; ++j)
        {
            unsigned int grade;
            cin >> grade;

            points += grade;
        }

        if (points > winner_points)
        {
            winner_number = i;
            winner_points = points;
        }
    }

    cout << winner_number << ' ' << winner_points << '\n';

    return 0;
}
