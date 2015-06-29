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

    for (unsigned int i {1}; i <= upper_limit; i += 2)
    {
        cout << i << '\n';
    }

    return 0;
}
