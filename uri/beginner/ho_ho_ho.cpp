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

    unsigned int count;
    cin >> count;

    for (unsigned int i {0}; i < count; ++i)
    {
        cout << "Ho" << (i + 1 < count ? ' ' : '!');
    }

    cout << '\n';

    return 0;
}
