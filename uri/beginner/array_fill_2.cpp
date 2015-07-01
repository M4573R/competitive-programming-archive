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

    for (unsigned int i {0}; i < 1000; ++i)
    {
        cout << "N[" << i << "] = " << i % upper_limit << '\n';
    }

    return 0;
}
