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
        unsigned int rooms;
        cin >> rooms;

        unsigned int missing {0};

        for (unsigned int i {1}; i <= rooms; ++i)
        {
            missing ^= i;
        }

        for (unsigned int i {0}; i < rooms - 1; ++i)
        {
            unsigned int room;
            cin >> room;

            missing ^= room;
        }

        cout << missing << '\n';
    }

    return 0;
}
