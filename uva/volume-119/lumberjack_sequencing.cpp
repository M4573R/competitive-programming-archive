#include <iostream>

using namespace std;

constexpr unsigned int group_size {10};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << "Lumberjacks:\n";

    unsigned int groups;
    cin >> groups;

    for (unsigned int i {0}; i < groups; ++i)
    {
        bool increasing {false};
        bool decreasing {false};

        unsigned int current;
        cin >> current;

        for (unsigned int j {1}; j < group_size; ++j)
        {
            unsigned int next;
            cin >> next;

            if (current < next)
            {
                increasing = true;
            }
            else if (current > next)
            {
                decreasing = true;
            }

            current = next;
        }

        cout << (increasing && decreasing ? "Unordered" : "Ordered") << '\n';
    }

    return 0;
}
