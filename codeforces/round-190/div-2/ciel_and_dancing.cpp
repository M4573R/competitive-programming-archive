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

    unsigned int boys;
    unsigned int girls;

    cin >> boys >> girls;

    cout << boys + girls - 1 << '\n';

    for (unsigned int i {1}; i <= boys; ++i)
    {
        cout << i << ' ' << 1 << '\n';
    }

    for (unsigned int i {2}; i <= girls; ++i)
    {
        cout << 1 << ' ' << i << '\n';
    }

    return 0;
}
