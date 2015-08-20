#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int>::size_type winner(const vector<unsigned int>& points)
{
    vector<unsigned int>::size_type maximum {0};

    for (vector<unsigned int>::size_type i {0}; i < points.size(); ++i)
    {
        if (points[i] > points[maximum])
        {
            maximum = i;
        }
    }

    return maximum;
}

int main()
{
    use_io_optimizations();

    unsigned int candidates;
    unsigned int cities;

    cin >> candidates >> cities;

    vector<unsigned int> wins(candidates);

    for (unsigned int i {0}; i < cities; ++i)
    {
        vector<unsigned int> votes(candidates);

        for (auto& count : votes)
        {
            cin >> count;
        }

        ++wins[winner(votes)];
    }

    cout << winner(wins) + 1 << '\n';

    return 0;
}
