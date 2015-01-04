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

    unsigned int stripes;
    cin >> stripes;

    unsigned int a {0};
    unsigned int b {1};

    for (unsigned int i {1}; i < stripes; ++i)
    {
        unsigned int c {a + b};

        a = b;
        b = c;
    }

    cout << 2 * b << '\n';

    return 0;
}
