#include <algorithm>
#include <iostream>
#include <set>
#include <string>
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

    unsigned int students;
    unsigned int subjects;

    cin >> students >> subjects;

    vector<string> grades(students);

    for (unsigned int i {0}; i < students; ++i)
    {
        cin >> grades[i];
    }

    set<unsigned int> successful;

    for (unsigned int i {0}; i < subjects; ++i)
    {
        char max_grade {'0'};

        for (unsigned int j {0}; j < students; ++j)
        {
            max_grade = max(max_grade, grades[j][i]);
        }

        for (unsigned int j {0}; j < students; ++j)
        {
            if (max_grade == grades[j][i])
            {
                successful.insert(j);
            }
        }
    }

    cout << successful.size() << '\n';

    return 0;
}
