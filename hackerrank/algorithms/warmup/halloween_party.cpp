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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned long long cuts;
        cin >> cuts;

        unsigned long long horizontal_cuts {cuts / 2};
        unsigned long long vertical_cuts   {cuts - horizontal_cuts};

        cout << horizontal_cuts * vertical_cuts << '\n';
    }

    return 0;
}
