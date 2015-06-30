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

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

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

    return 0;
}
