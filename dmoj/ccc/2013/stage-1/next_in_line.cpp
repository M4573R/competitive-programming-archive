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

    unsigned int youngest;
    unsigned int middle;

    cin >> youngest >> middle;

    cout << middle + (middle - youngest) << '\n';

    return 0;
}
