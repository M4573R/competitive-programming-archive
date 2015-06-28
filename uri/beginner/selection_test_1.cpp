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

    int a;
    int b;
    int c;
    int d;

    cin >> a >> b >> c >> d;

    if (b > c         &&
        d > a         &&
        c + d > a + b &&
        c > 0         &&
        d > 0         &&
        a % 2 == 0)
    {
        cout << "Valores aceitos\n";
    }
    else
    {
        cout << "Valores nao aceitos\n";
    }

    return 0;
}
