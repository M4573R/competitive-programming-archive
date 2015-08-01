#include <iostream>

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
        unsigned int lower_bound;

        cin >> students >> lower_bound;

        unsigned int in_time {0};

        for (unsigned int i {0}; i < students; ++i)
        {
            int arrival_time;
            cin >> arrival_time;

            if (arrival_time <= 0)
            {
                ++in_time;
            }
        }

        cout << (in_time < lower_bound ? "YES" : "NO") << '\n';
    }

    return 0;
}
