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

    for (unsigned int left, right; cin >> left >> right; )
    {
        cout << (left ^ right) << '\n';
    }

    return 0;
}
