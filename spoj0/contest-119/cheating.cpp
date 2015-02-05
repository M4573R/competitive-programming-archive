#include <iostream>
#include <queue>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void initialize_network(vector< vector<unsigned int> >& links,
                        vector< vector<unsigned int> >& capacities,
                        const vector<unsigned int>& student_rows)
{
    unsigned int students = student_rows.size();
    unsigned int source   = 2 * students;
    unsigned int sink     = 2 * students + 1;

    for (unsigned int i = 0; i < students; ++i)
    {
        links[source].push_back(i);
        links[i].push_back(source);
        capacities[source][i] = 1;

        links[i + students].push_back(sink);
        links[sink].push_back(i + students);
        capacities[i + students][sink] = 1;
    }
}

void connect(unsigned int first,
             unsigned int second,
             vector< vector<unsigned int> >& links,
             vector< vector<unsigned int> >& capacities)
{
    links[first].push_back(second);
    links[second].push_back(first);
    capacities[first][second] = 1;
}

void update_capacities(vector< vector<unsigned int> >& capacities,
                       const vector<int>& parents,
                       unsigned int sink)
{
    for (unsigned int i = sink; parents[i] != -1; i = parents[i])
    {
        --capacities[parents[i]][i];
        ++capacities[i][parents[i]];
    }
}

unsigned int bfs(const vector< vector<unsigned int> >& links,
                 vector< vector<unsigned int> >& capacities)
{
    unsigned int source = links.size() - 2;
    unsigned int sink   = links.size() - 1;

    vector<bool> visited(links.size());
    vector<int> parents(links.size(), -1);
    queue<unsigned int> levels;

    levels.push(source);
    visited[source] = true;

    bool at_sink = false;

    while (!levels.empty() && !at_sink)
    {
        unsigned int current = levels.front();
        levels.pop();

        for (unsigned int i = 0; i < links[current].size() && !at_sink; ++i)
        {
            unsigned int adjacent = links[current][i];

            if (!visited[adjacent] && capacities[current][adjacent])
            {
                visited[adjacent] = true;
                parents[adjacent] = current;
                levels.push(adjacent);

                at_sink = (adjacent == sink);
            }
        }
    }

    update_capacities(capacities, parents, sink);

    return at_sink;
}

unsigned int max_matching(const vector< vector<unsigned int> >& links,
                          vector< vector<unsigned int> >& capacities)
{
    unsigned int flow = 0;

    for (unsigned int augment; augment = bfs(links, capacities); )
    {
        flow += augment;
    }

    return flow;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned int students;
        unsigned int pairs;
        unsigned int rows;

        cin >> students >> pairs >> rows;

        vector<unsigned int> student_rows(students);

        for (unsigned int i = 0; i < students; ++i)
        {
            cin >> student_rows[i];
        }
        vector< vector<unsigned int> > links(2 * students + 2);
        vector< vector<unsigned int> > capacities(
            2 * students + 2,
            vector<unsigned int>(2 * students + 2)
        );

        initialize_network(links, capacities, student_rows);

        for (unsigned int i = 0; i < pairs; ++i)
        {
            unsigned int first;
            unsigned int second;

            cin >> first >> second;

            if (student_rows[first] == student_rows[second] + 1)
            {
                connect(first, second + students, links, capacities);

            }
            else if (student_rows[second] == student_rows[first] + 1)
            {
                connect(second, first + students, links, capacities);
            }
        }

        cout << max_matching(links, capacities) << '\n';
    }

    return 0;
}
