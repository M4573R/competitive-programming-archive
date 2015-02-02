#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int integers_count;
        cin >> integers_count;

        unsigned int sum {0};
        vector<unsigned int> integers(integers_count);

        for (auto& integer : integers)
        {
            cin >> integer;
            sum += integer;
        }

        unsigned long long subset_sums {0};
        vector<bool> subtasks(sum + 1);

        for (auto integer : integers)
        {
            for (unsigned int i {sum + 1}; i-- > integer; )
            {
                if (!subtasks[i] && (subtasks[i - integer] || i == integer))
                {
                    subtasks[i] = 1;
                    subset_sums += i;
                }
            }
        }

        cout << subset_sums << '\n';
    }

    return 0;
}
