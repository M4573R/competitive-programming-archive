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

    for (int number; cin >> number && number != 0; )
    {
        if (number % 2)
        {
            ++number;
        }

        cout << 5 * number + 20 << '\n';
    }

    return 0;
}
