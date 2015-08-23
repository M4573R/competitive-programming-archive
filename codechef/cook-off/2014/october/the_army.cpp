#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    int test_cases;
    cin >> test_cases;

    for (int i {0}; i < test_cases; ++i)
    {
        int soldiers;
        int rounds;

        cin >> soldiers >> rounds;

        int min_position {soldiers - 1};
        int max_position {0};

        for (int j {0}; j < rounds; ++j)
        {
            int position;
            cin >> position;

            min_position = min(min_position, position);
            max_position = max(max_position, position);
        }

        for (int soldier {0}; soldier < soldiers; ++soldier)
        {
            cout << max(soldier - min_position, max_position - soldier);

            if (soldier < soldiers - 1)
            {
                cout << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
