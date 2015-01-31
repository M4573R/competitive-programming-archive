#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int max_teams(unsigned int students, const vector<unsigned int>& groups)
{
    vector<int> computed(students + 2, numeric_limits<int>::min());
    computed[students] = 0;

    for (unsigned int i = students - 1; i-- > 0; )
    {
        if (groups[i] == groups[i + 1])
        {
            computed[i] = max(computed[i], computed[i + 2] + 1);
            computed[i] = max(computed[i], computed[i + 3] + 1);
        }

        if (groups[i] == groups[i + 2] || groups[i + 1] == groups[i + 2])
        {
            computed[i] = max(computed[i], computed[i + 3] + 1);
        }
    }

    return max(-1, computed.front());
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned int students;
        cin >> students;

        vector<unsigned int> groups(students);

        for (unsigned int i = 0; i < students; ++i)
        {
            cin >> groups[i];
        }

        cout << max_teams(students, groups) << '\n';
    }

    return 0;
}
