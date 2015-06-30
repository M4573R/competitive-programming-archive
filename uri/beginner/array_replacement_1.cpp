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

    for (unsigned int i {0}; i < 10; ++i)
    {
        int number;
        cin >> number;

        cout << "X[" << i << "] = " << (number <= 0 ? 1 : number) << '\n';
    }

    return 0;
}
