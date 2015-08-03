#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Point
{
    int x;
    int y;
};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        Point first;
        Point second;

        cin >> first.x  >> first.y
            >> second.x >> second.y;

        cout << 2 * second.x - first.x << ' '
             << 2 * second.y - first.y << '\n';
    }

    return 0;
}
