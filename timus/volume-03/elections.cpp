#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    unsigned int candidates;
    unsigned int electors;

    cin >> candidates >> electors;

    vector<int> candidate_votes(candidates);

    for (unsigned int i {0}; i < electors; ++i)
    {
        unsigned int candidate;
        cin >> candidate;

        ++candidate_votes[candidate - 1];
    }

    for (auto votes : candidate_votes)
    {
        cout << 100.0 * votes / electors << "%\n";
    }

    return 0;
}
