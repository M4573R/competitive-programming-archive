#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

inline void use_io_optimizations()
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
        unsigned int stones;
        unsigned int first_difference;
        unsigned int second_difference;

        cin >> stones >> first_difference >> second_difference;

        unsigned int min_difference {min(first_difference, second_difference)};
        unsigned int max_difference {max(first_difference, second_difference)};

        set<unsigned int> last_stones;

        for (unsigned int i {0}; i < stones; ++i)
        {
            last_stones.insert(max_difference * i +
                               min_difference * (stones - 1 - i));
        }

        for (auto stone = last_stones.cbegin(); stone != last_stones.cend(); ++stone)
        {
            if (stone != last_stones.cbegin())
            {
                cout << ' ';
            }

            cout << *stone;
        }

        cout << '\n';
    }

    return 0;
}
