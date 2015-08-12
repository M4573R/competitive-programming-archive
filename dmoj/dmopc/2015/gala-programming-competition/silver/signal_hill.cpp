#include <iostream>
#include <queue>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Circle
{
    int x;
    int y;
    int radius;
};

inline
int squared_distance(const Circle& left, const Circle& right)
{
    return ((left.x - right.x) * (left.x - right.x) +
            (left.y - right.y) * (left.y - right.y));
}

bool are_connected(unsigned int origin,
                   unsigned int target,
                   const vector<vector<unsigned int>>& graph)
{
    queue<unsigned int> level;
    level.push(origin);

    vector<bool> visited(graph.size());
    visited[origin] = true;

    while (!level.empty())
    {
        auto current = level.front();
        level.pop();

        for (auto adjacent : graph[current])
        {
            if (!visited[adjacent])
            {
                if (adjacent == target)
                {
                    return true;
                }

                level.push(adjacent);
                visited[adjacent] = true;
            }
        }
    }

    return false;
}

int main()
{
    use_io_optimizations();

    unsigned int beacons;
    unsigned int queries;

    cin >> beacons >> queries;

    vector<Circle> circles(beacons + 1);
    vector<vector<unsigned int>> graph(beacons + 1);

    for (unsigned int i {1}; i <= beacons; ++i)
    {
        cin >> circles[i].x >> circles[i].y >> circles[i].radius;

        for (unsigned int j {1}; j < i; ++j)
        {
            auto distance = squared_distance(circles[i], circles[j]);

            if (distance <= circles[i].radius * circles[i].radius)
            {
                graph[i].push_back(j);
            }

            if (distance <= circles[j].radius * circles[j].radius)
            {
                graph[j].push_back(i);
            }
        }
    }

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int origin;
        unsigned int target;

        cin >> origin >> target;

        cout << (are_connected(origin, target, graph) ? "YES" : "NO") << '\n';
    }

    return 0;
}
