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

    unsigned int length;
    cin >> length;

    if (length % 2)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (unsigned int i {length}; i >= 1; --i)
        {
            cout << i << " \n"[i == 1];
        }
    }

    return 0;
}
