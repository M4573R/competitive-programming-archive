#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

unsigned int min_time_to_toilet(const vector< vector<unsigned int> >& field,
                                const vector< vector<unsigned int> >& costs)
{
    unsigned int rows    = field.size();
    unsigned int columns = field.front().size();

    vector< vector<unsigned int> > subtasks(rows, vector<unsigned int>(columns));

    for (unsigned int i = 1; i < columns; ++i)
    {
        subtasks[0][i] = (subtasks[0][i - 1] +
                          costs[field[0][i - 1]][field[0][i]]);
    }

    for (unsigned int i = 1; i < rows; ++i)
    {
        subtasks[i][0] = (subtasks[i - 1][0] +
                          costs[field[i - 1][0]][field[i][0]]);
    }

    for (unsigned int i = 1; i < rows; ++i)
    {
        for (unsigned int j = 1; j < columns; ++j)
        {
            subtasks[i][j] = min(
                subtasks[i - 1][j] + costs[field[i - 1][j]][field[i][j]],
                subtasks[i][j - 1] + costs[field[i][j - 1]][field[i][j]]
            );
        }
    }

    return subtasks[rows - 1][columns - 1];
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned int rows;
        unsigned int columns;
        unsigned int transitions;

        cin >> rows >> columns >> transitions;

        vector< vector<unsigned int> > costs(26, vector<unsigned int>(26));

        for (unsigned int i = 0; i < transitions; ++i)
        {
            char from;
            char to;
            unsigned int cost;

            cin >> from >> to >> cost;

            costs[from - 'a'][to - 'a'] = cost;
        }

        vector< vector<unsigned int> > field(rows, vector<unsigned int>(columns));

        for (unsigned int i = 0; i < rows; ++i)
        {
            for (unsigned int j = 0; j < columns; ++j)
            {
                char terrain;
                cin >> terrain;

                field[i][j] = terrain - 'a';
            }
        }

        cout << min_time_to_toilet(field, costs) << '\n';
    }

    return 0;
}
