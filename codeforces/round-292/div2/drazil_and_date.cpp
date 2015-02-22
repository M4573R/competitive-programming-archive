#include <cstdlib>
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

    int x;
    int y;
    int steps;

    cin >> x >> y >> steps;

    int shortest_path {abs(x) + abs(y)};

    if (shortest_path > steps || shortest_path % 2 != steps % 2)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }

    cout << '\n';

    return 0;
}
