#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
bool is_done()
{
    cout << "Novo grenal (1-sim 2-nao)\n";

    unsigned int answer;
    cin >> answer;

    return answer == 2;
}

void print_statistics(unsigned int inter_wins,
                      unsigned int gremio_wins,
                      unsigned int draws)
{
    unsigned int matches {inter_wins + gremio_wins + draws};

    cout << matches    << " grenais"  << '\n'
         << "Inter:"   << inter_wins  << '\n'
         << "Gremio:"  << gremio_wins << '\n'
         << "Empates:" << draws       << '\n';

    if (inter_wins < gremio_wins)
    {
        cout << "Gremio venceu mais";
    }
    else if (inter_wins > gremio_wins)
    {
        cout << "Inter venceu mais";
    }
    else
    {
        cout << "Nao houve vencedor";
    }

    cout << '\n';
}

int main()
{
    use_io_optimizations();

    unsigned int inter_wins  {0};
    unsigned int gremio_wins {0};
    unsigned int draws       {0};

    for (bool done {false}; !done; done = is_done())
    {
        unsigned int inter_goals;
        unsigned int gremio_goals;

        cin >> inter_goals >> gremio_goals;

        if (inter_goals < gremio_goals)
        {
            ++gremio_wins;
        }
        else if (inter_goals > gremio_goals)
        {
            ++inter_wins;
        }
        else
        {
            ++draws;
        }
    }

    print_statistics(inter_wins, gremio_wins, draws);

    return 0;
}
