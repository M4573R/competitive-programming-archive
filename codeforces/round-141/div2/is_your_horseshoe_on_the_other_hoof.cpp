#include <iostream>
#include <set>

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

    set<unsigned int> colors;

    for (unsigned int i {0}; i < 4; ++i)
    {
        unsigned int color;
        cin >> color;

        colors.insert(color);
    }

    cout << 4 - colors.size() << '\n';

    return 0;
}
