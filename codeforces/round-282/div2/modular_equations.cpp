#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int a;
    unsigned int b;

    cin >> a >> b;

    if (a < b)
    {
        cout << "0\n";
        return 0;
    }

    if (a == b)
    {
        cout << "infinity\n";
        return 0;
    }

    unsigned int c {a - b};
    unsigned int solutions {0};

    for (unsigned int i {1}; i * i <= c; ++i)
    {
        if (c % i == 0)
        {
            if (i > b)
            {
                ++solutions;
            }

            if (i * i != c && c / i > b)
            {
                ++solutions;
            }
        }
    }

    cout << solutions << '\n';

    return 0;
}
