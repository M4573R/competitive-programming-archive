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

    unsigned int multiplications;
    cin >> multiplications;

    for (unsigned int i {0}; i < multiplications; ++i)
    {
        long long left;
        long long right;
        long long product;

        cin >> left >> right >> product;

        if (left * right == product)
        {
            cout << "POSSIBLE DOUBLE SIGMA";
        }
        else
        {
            cout << "16 BIT S/W ONLY";
        }

        cout << '\n';
    }

    return 0;
}
