#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int max_strokes {6000};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int min_strokes(unsigned int to_hole,
                         const vector<unsigned int>& distances)
{
    vector<unsigned int> strokes(to_hole + 1, max_strokes);

    strokes[0] = 0;

    for (unsigned int i {0}; i < to_hole; ++i)
    {
        for (auto distance : distances)
        {
            if (i + distance <= to_hole)
            {
                strokes[i + distance] = min(strokes[i + distance],
                                            strokes[i] + 1);
            }
        }
    }

    return strokes[to_hole];
}

int main()
{
    use_io_optimizations();

    unsigned int to_hole;
    cin >> to_hole;

    unsigned int clubs;
    cin >> clubs;

    vector<unsigned int> distances(clubs);

    for (auto& distance : distances)
    {
        cin >> distance;
    }

    unsigned int strokes_to_hole {min_strokes(to_hole, distances)};

    if (strokes_to_hole == max_strokes)
    {
        cout << "Roberta acknowledges defeat.";
    }
    else
    {
        cout << "Roberta wins in " << strokes_to_hole << " strokes.";
    }

    cout << '\n';

    return 0;
}
