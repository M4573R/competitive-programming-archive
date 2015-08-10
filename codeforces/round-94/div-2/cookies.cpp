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

    unsigned int bags;
    cin >> bags;

    unsigned int odd {0};

    for (unsigned int i {0}; i < bags; ++i)
    {
        unsigned int cookies;
        cin >> cookies;

        if (cookies % 2)
        {
            ++odd;
        }
    }

    cout << (odd % 2 ? odd : bags - odd) << '\n';

    return 0;
}
