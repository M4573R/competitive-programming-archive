#include <iomanip>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
bool is_valid(double score)
{
    return score >= 0 && score <= 10;
}

bool is_done()
{
    unsigned int answer;

    do
    {
        cout << "novo calculo (1-sim 2-nao)\n";

    } while (cin >> answer && answer != 1 && answer != 2);

    return answer == 2;
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    for (bool done {false}; !done; done = is_done())
    {
        double total_score {0};

        for (unsigned int valid_scores {0}; valid_scores < 2; )
        {
            double score;
            cin >> score;

            if (is_valid(score))
            {
                total_score += score;
                ++valid_scores;
            }
            else
            {
                cout << "nota invalida\n";
            }
        }

        cout << "media = " << total_score / 2 << '\n';
    }

    return 0;
}
