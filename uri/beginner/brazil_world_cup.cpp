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

    for (unsigned int complaints; cin >> complaints; )
    {
        cout << (complaints ? "vai ter duas!" : "vai ter copa!") << '\n';
    }

    return 0;
}
