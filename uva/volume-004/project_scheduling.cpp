#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

constexpr unsigned int vertices {27};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> topsort(const vector<vector<unsigned int>>& links)
{
    vector<unsigned int> sorted;
    vector<unsigned int> remaining;
    vector<unsigned int> indegrees(vertices);

    for (unsigned int vertex {0}; vertex < vertices; ++vertex)
    {
        for (auto adjacent : links[vertex])
        {
            ++indegrees[adjacent];
        }
    }

    for (unsigned int vertex {0}; vertex < vertices; ++vertex)
    {
        if (indegrees[vertex] == 0)
        {
            remaining.push_back(vertex);
        }
    }

    while (!remaining.empty())
    {
        unsigned int current {remaining.back()};

        remaining.pop_back();
        sorted.push_back(current);

        for (auto adjacent : links[current])
        {
            --indegrees[adjacent];

            if (indegrees[adjacent] == 0)
            {
                remaining.push_back(adjacent);
            }
        }
    }

    return sorted;
}

unsigned int needed_time(const vector<vector<unsigned int>>& links,
                         const vector<unsigned int>& times)
{
    vector<unsigned int> topsorted {topsort(links)};
    vector<unsigned int> finish_times(vertices);

    for (auto vertex : topsorted)
    {
        finish_times[vertex] += times[vertex];

        for (auto adjacent : links[vertex])
        {
            finish_times[adjacent] = max(finish_times[adjacent],
                                         finish_times[vertex]);
        }
    }

    return *max_element(finish_times.begin(), finish_times.end());
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    cin.get();
    cin.get();

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        vector<vector<unsigned int>> links(vertices);
        vector<unsigned int> times(vertices);

        for (string line; getline(cin, line) && !line.empty(); )
        {
            istringstream input {line};

            char vertex;
            input >> vertex;
            input >> times[vertex - 'A'];

            for (char neighbour; input >> neighbour; )
            {
                links[neighbour - 'A'].push_back(vertex - 'A');
            }
        }

        cout << needed_time(links, times) << '\n';

        if (test < test_cases - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
