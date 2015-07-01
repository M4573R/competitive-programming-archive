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

    unsigned int start_x;
    unsigned int start_y;

    unsigned int end_x;
    unsigned int end_y;

    while (cin >> start_x >> start_y >> end_x >> end_y &&
           (start_x != 0 || start_y != 0 || end_x != 0 || end_y != 0))
    {
        if (start_x == end_x && start_y == end_y)
        {
            cout << 0;
        }
        else if (start_x == end_x ||
                 start_y == end_y ||
                 start_x + start_y == end_x + end_y ||
                 start_x + end_y == end_x + start_y)
        {
            cout << 1;
        }
        else
        {
            cout << 2;
        }

        cout << '\n';
    }

    return 0;
}
