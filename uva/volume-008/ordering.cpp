#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void print_topsort(const string& topsort)
{
    cout << topsort.front();

    for (string::size_type i {1}; i < topsort.size(); ++i)
    {
        cout << ' ' << topsort[i];
    }

    cout << '\n';
}

bool topsorts(string topsort,
              const vector<char>& variables,
              const vector<vector<char>>& graph,
              vector<bool>& visited,
              vector<unsigned int>& in_degrees)
{
    if (topsort.size() == variables.size())
    {
        print_topsort(topsort);
        return true;
    }

    bool is_dag {false};

    for (auto& variable : variables)
    {
        if (!visited[variable] && !in_degrees[variable])
        {
            visited[variable] = true;

            for (auto adjacent : graph[variable])
            {
                --in_degrees[adjacent];
            }

            is_dag |= topsorts(topsort + variable, variables, graph, visited, in_degrees);

            visited[variable] = false;

            for (auto adjacent : graph[variable])
            {
                ++in_degrees[adjacent];
            }
        }
    }
    return is_dag;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;
    cin.get();

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string line;
        istringstream input;

        cin.get();
        getline(cin, line);
        input.str(line);

        vector<char> variables;

        for (char variable; input >> variable; )
        {
            variables.push_back(variable);
        }

        sort(variables.begin(), variables.end());

        vector<vector<char>> graph(256);
        vector<unsigned int> in_degrees(256);

        getline(cin, line);
        input.clear();
        input.str(line);

        for (char left, sign, right; input >> left >> sign >> right; )
        {
            graph[left].push_back(right);
            ++in_degrees[right];
        }

        vector<bool> visited(256);

        if (!topsorts("", variables, graph, visited, in_degrees))
        {
            cout << "NO\n";
        }

        if (test < test_cases - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
