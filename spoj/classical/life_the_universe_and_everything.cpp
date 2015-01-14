#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    int input_number;

    while (cin >> input_number && input_number != 42)
    {
        cout << input_number << '\n';
    }

    return 0;
}
