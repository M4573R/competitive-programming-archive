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

    unsigned int initial;
    unsigned int target;

    cin >> initial >> target;

    unsigned int clicks {0};

    while (initial < target)
    {
        if (target % 2 != 0)
        {
            ++target;
            ++clicks;
        }

        target /= 2;
        ++clicks;
    }

    clicks += (initial - target);

    cout << clicks << '\n';

    return 0;
}
