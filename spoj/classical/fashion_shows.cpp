#include <algorithm>
#include <iostream>
#include <vector>

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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int participants;
        cin >> participants;

        vector<unsigned int> men_ratings(participants);

        for (auto& rating : men_ratings)
        {
            cin >> rating;
        }

        vector<unsigned int> women_ratings(participants);

        for (auto& rating : women_ratings)
        {
            cin >> rating;
        }

        sort(men_ratings.begin(),   men_ratings.end());
        sort(women_ratings.begin(), women_ratings.end());

        unsigned int max_rating {0};

        for (unsigned int i {0}; i < participants; ++i)
        {
            max_rating += men_ratings[i] * women_ratings[i];
        }

        cout << max_rating << '\n';
    }

    return 0;
}
