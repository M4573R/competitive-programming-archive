#include <cstdlib>
#include <iostream>

using namespace std;

constexpr int player_one {1};
constexpr int player_two {2};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    int rounds;
    cin >> rounds;

    int winner;
    int winner_lead {0};

    int player_one_total_score {0};
    int player_two_total_score {0};

    for (int i {0}; i < rounds; ++i)
    {
        int player_one_points;
        int player_two_points;

        cin >> player_one_points >> player_two_points;

        player_one_total_score += player_one_points;
        player_two_total_score += player_two_points;

        int round_lead = abs(player_one_total_score - player_two_total_score);

        if (round_lead > winner_lead)
        {
            if (player_one_total_score > player_two_total_score)
            {
                winner = player_one;
            }
            else
            {
                winner = player_two;
            }

            winner_lead = round_lead;
        }
    }

    cout << winner << " " << winner_lead << '\n';

    return 0;
}
