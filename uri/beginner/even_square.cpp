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

    unsigned int upper_limit;
    cin >> upper_limit;

    for (unsigned int i {2}; i <= upper_limit; i += 2)
    {
        cout << i << '^' << 2 << " = " << i * i << '\n';
    }

    return 0;
}
