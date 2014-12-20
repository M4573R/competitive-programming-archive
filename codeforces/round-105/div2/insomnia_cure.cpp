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

    unsigned int k;
    unsigned int l;
    unsigned int m;
    unsigned int n;

    cin >> k >> l >> m >> n;

    unsigned int dragons;
    cin >> dragons;

    unsigned int damaged {0};

    for (unsigned int i {1}; i <= dragons; ++i)
    {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
        {
            ++damaged;
        }
    }

    cout << damaged << '\n';

    return 0;
}
