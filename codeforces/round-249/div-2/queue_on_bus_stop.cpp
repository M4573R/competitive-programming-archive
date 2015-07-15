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

    unsigned int groups;
    unsigned int capacity;

    cin >> groups >> capacity;

    unsigned int buses {0};
    unsigned int seats {0};

    for (unsigned int i {0}; i < groups; ++i)
    {
        unsigned int people;
        cin >> people;

        if (people > seats)
        {
            ++buses;
            seats = capacity;
        }

        seats -= people;
    }

    cout << buses << '\n';

    return 0;
}
