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

    unsigned int lines;
    cin >> lines;

    for (unsigned int i {1}; i <= lines; ++i)
    {
        cout << i << ' ' << i * i << ' ' << i * i * i << '\n';
    }

    return 0;
}
