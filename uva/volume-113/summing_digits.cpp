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

    for (unsigned int number; cin >> number && number != 0;)
    {
        cout << (number % 9 == 0 ? 9 : number % 9) << '\n';
    }

    return 0;
}
