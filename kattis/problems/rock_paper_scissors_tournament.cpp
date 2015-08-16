#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
bool first_wins(const string& first, const string& second)
{
    static const map<string, string> wins_against {
        {"paper",    "rock"},
        {"scissors", "paper"},
        {"rock",     "scissors"}
    };

    return wins_against.at(first) == second;
}

void process_games(unsigned int games,
                   vector<unsigned int>& wins,
                   vector<unsigned int>& losses)
{
    for (unsigned int i {0}; i < games; ++i)
    {
        unsigned int first_player;
        unsigned int second_player;

        string first_move;
        string second_move;

        cin >> first_player  >> first_move
            >> second_player >> second_move;

        if (first_wins(first_move, second_move))
        {
            ++wins[first_player - 1];
            ++losses[second_player - 1];
        }
        else if (first_wins(second_move, first_move))
        {
            ++wins[second_player - 1];
            ++losses[first_player - 1];
        }
    }
}

void print_win_averages(const vector<unsigned int>& wins,
                        const vector<unsigned int>& losses)
{
    for (vector<unsigned int>::size_type i {0}; i < wins.size(); ++i)
    {
        if (wins[i] + losses[i] == 0)
        {
            cout << '-';
        }
        else
        {
            cout << static_cast<double>(wins[i]) / (wins[i] + losses[i]);
        }

        cout << '\n';
    }
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(3);

    unsigned int players;
    unsigned int rounds;

    for (unsigned int test {0}; cin >> players >> rounds; ++test)
    {
        if (test > 0)
        {
            cout << '\n';
        }

        unsigned int games {rounds * players * (players - 1) / 2};

        vector<unsigned int> wins(players);
        vector<unsigned int> losses(players);

        process_games(games, wins, losses);
        print_win_averages(wins, losses);
    }

    return 0;
}
