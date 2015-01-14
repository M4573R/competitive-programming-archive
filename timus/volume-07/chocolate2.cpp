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

    unsigned int rows;
    unsigned int columns;

    cin >> rows >> columns;

    cout << (rows * columns % 2 == 0 ? "[:=[first]" : "[second]=:]") << '\n';

    return 0;
}
