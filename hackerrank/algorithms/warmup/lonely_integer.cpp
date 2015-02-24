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

    unsigned int lonely_integer;

    unsigned int integers;
    cin >> integers;

    for (unsigned int i {0}; i < integers; ++i)
    {
        unsigned int integer;
        cin >> integer;

        lonely_integer ^= integer;
    }

    cout << lonely_integer << '\n';

    return 0;
}
