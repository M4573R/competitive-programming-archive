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

    unsigned int hobbits;
    unsigned int couples;

    cin >> hobbits >> couples;

    cout << hobbits * (hobbits - 1) / 2 - couples << '\n';

    return 0;
}
