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

    for (int number; cin >> number && number != 42; )
    {
        cout << number << '\n';
    }

    return 0;
}
