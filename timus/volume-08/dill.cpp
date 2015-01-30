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

    unsigned int boxed_of_first;
    unsigned int boxes_of_second;

    cin >> boxed_of_first >> boxes_of_second;

    for (unsigned int i {1}; i <= boxed_of_first; ++i)
    {
        cout << i;

        if (i < boxed_of_first)
        {
            cout << ' ';
        }
    }

    cout << '\n';

    for (unsigned int i {1}; i <= boxes_of_second; ++i)
    {
        cout << i * boxed_of_first + 1;

        if (i < boxes_of_second)
        {
            cout << ' ';
        }
    }

    cout << '\n';

    return 0;
}
