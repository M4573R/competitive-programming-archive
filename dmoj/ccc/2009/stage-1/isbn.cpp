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

    unsigned int a;
    unsigned int b;
    unsigned int c;

    cin >> a >> b >> c;

    cout << "The 1-3-sum is " << 91 + a + 3 * b + c << '\n';

    return 0;
}
