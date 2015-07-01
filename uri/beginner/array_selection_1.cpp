#include <iomanip>
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

    cout << fixed << setprecision(1);

    for (unsigned int i {0}; i < 100; ++i)
    {
        double number;
        cin >> number;

        if (number <= 10)
        {
            cout << "A[" << i << "] = " << number << '\n';
        }
    }

    return 0;
}
