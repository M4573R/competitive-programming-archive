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

    unsigned int dimensions;
    unsigned int items;

    cin >> dimensions >> items;

    unsigned int previous {items};

    for (unsigned int i {0}; i < dimensions; ++i)
    {
        unsigned int multiplier;
        cin >> multiplier;

        cout << previous / multiplier - 1 << '\n';

        previous = multiplier;
    }

    return 0;
}
