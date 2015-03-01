#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr unsigned int alphabet_size {26};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(unsigned int& names_count, vector<string>& names)
{
    cin >> names_count;

    names.resize(names_count);

    for (auto& name : names)
    {
        cin >> name;
    }
}

bool build_graph(const vector<string>& names,
                 vector<vector<unsigned int>>& graph,
                 vector<unsigned int>& degrees)
{
    graph.resize(alphabet_size);
    degrees.resize(alphabet_size);

    for (unsigned int i {0}; i < names.size() - 1; ++i)
    {
        unsigned int j {0};

        while (j < names[i].size()     &&
               j < names[i + 1].size() &&
               names[i][j] == names[i + 1][j])
        {
            ++j;
        }

        if (j < names[i].size() && j >= names[i + 1].size())
        {
            return false;
        }

        if (j < names[i].size() && j < names[i + 1].size())
        {
            graph[names[i][j] - 'a'].push_back(names[i + 1][j] - 'a');
            ++degrees[names[i + 1][j] - 'a'];
        }
    }

    return true;
}

vector<unsigned int> topsort(const vector<vector<unsigned int>>& graph,
                             vector<unsigned int>& degrees)
{
    vector<unsigned int> sorted;
    vector<unsigned int> remaining;

    for (unsigned int i {0}; i < alphabet_size; ++i)
    {
        if (degrees[i] == 0)
        {
            remaining.push_back(i);
        }
    }

    while (!remaining.empty())
    {
        unsigned int current {remaining.back()};

        sorted.push_back(current);
        remaining.pop_back();

        for (auto adjacent : graph[current])
        {
            --degrees[adjacent];

            if (degrees[adjacent] == 0)
            {
                remaining.push_back(adjacent);
            }
        }
    }

    return sorted;
}

void write_output(const vector<unsigned int>& degrees,
                  const vector<unsigned int>& sorted)
{
    for (auto degree : degrees)
    {
        if (degree)
        {
            cout << "Impossible\n";
            return;
        }
    }

    for (auto letter : sorted)
    {
        cout << static_cast<char>(letter + 'a');
    }

    cout << '\n';
}

int main()
{
    use_io_optimizations();

    unsigned int names_count;
    vector<string> names;

    read_input(names_count, names);

    vector<vector<unsigned int>> graph;
    vector<unsigned int> degrees;

    if (!build_graph(names, graph, degrees))
    {
        cout << "Impossible\n";
        return 0;
    }

    write_output(degrees, topsort(graph, degrees));

    return 0;
}
