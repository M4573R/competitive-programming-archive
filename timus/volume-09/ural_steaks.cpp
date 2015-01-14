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

    unsigned int steaks;
    unsigned int capacity;

    cin >> steaks >> capacity;

    unsigned int minutes {2 * (steaks / capacity)};

    if (steaks % capacity == 0)
    {
        cout << minutes;
    }
    else if ((steaks > capacity) && (steaks % capacity <= capacity / 2))
    {
        cout << minutes + 1;
    }
    else
    {
        cout << minutes + 2;
    }

    cout << '\n';

    return 0;
}
