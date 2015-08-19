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

    unsigned int numerator;
    unsigned int denominator;

    while (cin >> numerator >> denominator && (numerator || denominator))
    {
        cout << numerator / denominator << ' '
             << numerator % denominator << " / "
             << denominator             << '\n';
    }

    return 0;
}
