#include <algorithm>
#include <iostream>

using namespace std;

constexpr unsigned int min_position {0};
constexpr unsigned int max_position {99};

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

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int stores;
        cin >> stores;

        unsigned int leftmost  {max_position};
        unsigned int rightmost {min_position};

        for (unsigned int j {0}; j < stores; ++j)
        {
            unsigned int position;
            cin >> position;

            leftmost  = min(leftmost, position);
            rightmost = max(rightmost, position);
        }

        cout << 2 * (rightmost - leftmost) << '\n';
    }

    return 0;
}
