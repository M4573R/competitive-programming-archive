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

    unsigned int integer;
    cin >> integer;

    if (integer % 2 == 0)
    {
        cout << 4 << ' ' << integer - 4 << '\n';
    }
    else
    {
        cout << 9 << ' ' << integer - 9 << '\n';
    }

    return 0;
}
