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

unsigned int ways_count(const vector<unsigned int>& distances,
                        unsigned int lower_bound,
                        unsigned int upper_bound)
{
    vector<unsigned int> ways(7001);

    ways[0] = 1;

    for (auto distance : distances)
    {
        if (ways[distance])
        {
            unsigned int from {distance + lower_bound};
            unsigned int to   {min(7000u, distance + upper_bound)};

            for (unsigned int i {from}; i <= to; ++i)
            {
                ways[i] += ways[distance];
            }
        }
    }

    return ways.back();
}

int main()
{
    use_io_optimizations();

    vector<unsigned int> distances {
        0,    990,  1010, 1970, 2030, 2940, 3060,
        3930, 4060, 4970, 5030, 5990, 6010, 7000
    };

    unsigned int lower_bound;
    unsigned int upper_bound;

    cin >> lower_bound >> upper_bound;

    unsigned int additional_motels;
    cin >> additional_motels;

    for (unsigned int i {0}; i < additional_motels; ++i)
    {
        unsigned int distance;
        cin >> distance;

        distances.push_back(distance);
    }

    sort(distances.begin(), distances.end());

    cout << ways_count(distances, lower_bound, upper_bound) << '\n';

    return 0;
}
