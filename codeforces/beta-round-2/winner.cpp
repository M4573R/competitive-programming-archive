#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct BySecond
{
    bool operator()(const pair<string, int>& left,
                    const pair<string, int>& right)
    {
        return left.second < right.second;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int rounds;
    cin >> rounds;

    map<string, int> final_points;

    vector<string> names(rounds);
    vector<int>    scores(rounds);

    for (unsigned int i {0}; i < rounds; ++i)
    {
        cin >> names[i] >> scores[i];
        final_points[names[i]] += scores[i];
    }

    int max_points {max_element(final_points.cbegin(),
                                final_points.cend(),
                                BySecond())->second};

    map<string, int> points;

    for (unsigned int i {0}; i < rounds; ++i)
    {
        points[names[i]] += scores[i];

        if (points[names[i]] >= max_points &&
            final_points[names[i]] == max_points)
        {
            cout << names[i] << '\n';
            break;
        }
    }

    return 0;
}
