#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Position
{
    int x;
    int y;

    Position() = default;
};

class MinWeightedMatching
{
public:
    MinWeightedMatching(const vector<Position>& positions):
        students(positions.size()),
        computed(1 << students, -1),
        distances(students, vector<double>(students))
    {
        for (unsigned int i {0}; i < students - 1; ++i)
        {
            for (unsigned int j {i + 1}; j < students; ++j)
            {
                distances[i][j] = hypot(positions[i].x - positions[j].x,
                                        positions[i].y - positions[j].y);
                distances[j][i] = distances[i][j];
            }
        }
    }

    double find()
    {
        return find(0);
    }

    double find(unsigned int mask)
    {
        if (mask == (1 << students) - 1)
        {
            return 0;
        }

        if (computed[mask] != -1)
        {
            return computed[mask];
        }

        double weight {numeric_limits<double>::infinity()};

        unsigned int first;
        unsigned int second;

        for (first = 0; first < students && (mask & (1 << first)); ++first)
        { }

        for (second = first + 1; second < students; ++second)
        {
            if (!(mask & (1 << second)))
            {
                weight = min(weight,
                             distances[first][second] +
                             find(mask | (1 << first) | (1 << second)));
            }
        }

        return computed[mask] = weight;
    }

private:
    unsigned int students;

    vector<double> computed;
    vector<vector<double>> distances;
};

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    unsigned int teams;

    for (unsigned int test {1}; cin >> teams && teams != 0; ++test)
    {
        string name;
        vector<Position> positions(2 * teams);

        for (auto& position : positions)
        {
            cin >> name >> position.x >> position.y;
        }

        cout << "Case " << test << ": "
             << MinWeightedMatching{positions}.find()
             << '\n';
    }

    return 0;
}
