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

    unsigned int values;
    cin >> values;

    bool has_one {false};

    for (unsigned int i {0}; i < values; ++i)
    {
        unsigned int value;
        cin >> value;

        if (value == 1)
        {
            has_one = true;
        }
    }

    cout << (has_one ? -1 : 1) << '\n';

    return 0;
}

