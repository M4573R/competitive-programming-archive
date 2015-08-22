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

    unsigned int rounds;
    cin >> rounds;

    unsigned int winner      {0};
    unsigned int winner_lead {0};

    unsigned int first_score  {0};
    unsigned int second_score {0};

    for (unsigned int i {0}; i < rounds; ++i)
    {
        unsigned int first_points;
        unsigned int second_points;

        cin >> first_points >> second_points;

        first_score  += first_points;
        second_score += second_points;

        unsigned int round_lead {max(first_score, second_score) -
                                 min(first_score, second_score)};

        if (round_lead > winner_lead)
        {
            if (first_score > second_score)
            {
                winner = 1;
            }
            else
            {
                winner = 2;
            }

            winner_lead = round_lead;
        }
    }

    cout << winner << ' ' << winner_lead << '\n';

    return 0;
}
