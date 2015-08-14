#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

constexpr unsigned int max_color {19};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int min_money(const vector<vector<unsigned int>>& graph,
                       vector<vector<int>>& subtasks,
                       unsigned int node,
                       unsigned int color)
{
    if (subtasks[node][color] != -1)
    {
        return subtasks[node][color];
    }

    unsigned int minimum {numeric_limits<unsigned int>::max()};

    for (unsigned int i {1}; i <= max_color; ++i)
    {
        if (i != color)
        {
            unsigned int current {i};

            for (auto adjacent : graph[node])
            {
                current += min_money(graph, subtasks, adjacent, i);
            }

            minimum = min(minimum, current);
        }
    }

    return subtasks[node][color] = minimum;
}

unsigned int min_money(const vector<vector<unsigned int>>& graph)
{
    vector<vector<int>> subtasks(graph.size(), vector<int>(max_color + 1, -1));

    return min_money(graph, subtasks, 0, 0);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int employees;
        cin >> employees;

        vector<vector<unsigned int>> graph(employees);

        for (unsigned int i {0}; i < employees; ++i)
        {
            unsigned int manager;
            cin >> manager;

            if (manager > 0)
            {
                graph[manager - 1].push_back(i);
            }
        }

        cout << "Case #" << test << ": " << min_money(graph) << '\n';
    }

    return 0;
}
