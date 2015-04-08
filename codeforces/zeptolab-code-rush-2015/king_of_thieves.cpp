#include <iostream>
#include <string>

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

    unsigned int segments;
    cin >> segments;

    string level;
    cin >> level;

    for (unsigned int from {0}; from < segments; ++from)
    {
        for (unsigned int jump {1}; from + 4 * jump < segments; ++jump)
        {
            bool is_good {true};

            for (unsigned int i {0}; i < 5; ++i)
            {
                if (level[from + i * jump] != '*')
                {
                    is_good = false;
                }
            }

            if (is_good)
            {
                cout << "yes\n";
                return 0;
            }
        }
    }

    cout << "no\n";

    return 0;
}
