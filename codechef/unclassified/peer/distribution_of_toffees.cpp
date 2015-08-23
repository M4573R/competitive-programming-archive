#include <algorithm>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int students;
        cin >> students;

        vector<unsigned int> toffees(students);

        for (unsigned int i {0}; i < students; ++i)
        {
            cin >> toffees[i];
        }

        auto max_toffees = *max_element(toffees.cbegin(), toffees.cend());
        auto min_toffees = *min_element(toffees.cbegin(), toffees.cend());

        cout << (max_toffees - min_toffees < 2 ? "GOOD" : "BAD") << '\n';
    }

    return 0;
}
