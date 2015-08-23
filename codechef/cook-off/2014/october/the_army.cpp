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
        unsigned int soldiers;
        unsigned int rounds;

        cin >> soldiers >> rounds;

        unsigned int min_position {soldiers - 1};
        unsigned int max_position {0};

        for (unsigned int i {0}; i < rounds; ++i)
        {
            unsigned int position;
            cin >> position;

            min_position = min(min_position, position);
            max_position = max(max_position, position);
        }

        for (unsigned int i {0}; i < soldiers; ++i)
        {
            cout << max(static_cast<int>(i) - static_cast<int>(min_position),
                        static_cast<int>(max_position) - static_cast<int>(i))
                 << " \n"[i + 1 == soldiers];
        }
    }

    return 0;
}
