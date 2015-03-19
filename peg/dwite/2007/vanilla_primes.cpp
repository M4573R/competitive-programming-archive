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

    int number;
    cin >> number;

    if (number < 2)
    {
        cout << "not\n";
        return 0;
    }

    for (int i {2}; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            cout << "not\n";
            return 0;
        }
    }

    cout << "prime\n";

    return 0;
}
