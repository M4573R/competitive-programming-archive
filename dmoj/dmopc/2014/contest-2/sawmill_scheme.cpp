#include <iomanip>
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

    cout << fixed << setprecision(12);

    unsigned int lakes;
    unsigned int rivers;

    cin >> lakes >> rivers;

    vector<vector<unsigned int>> graph(lakes + 1);

    for (unsigned int i {0}; i < rivers; ++i)
    {
        unsigned int source;
        unsigned int destination;

        cin >> source >> destination;

        graph[source].push_back(destination);
    }

    vector<double> probabilities(lakes + 1);
    probabilities[1] = 1;

    for (unsigned int i {1}; i <= lakes; ++i)
    {
        if (graph[i].empty())
        {
            cout << probabilities[i] << '\n';
        }
        else
        {
            for (auto adjacent : graph[i])
            {
                probabilities[adjacent] += probabilities[i] / graph[i].size();
            }
        }
    }

    return 0;
}
