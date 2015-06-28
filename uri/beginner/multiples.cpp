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

    cin >> a >> b;

    if (a == 0 || b == 0 || a % b == 0 || b % a == 0)
    {
        cout << "Sao Multiplos";
    }
    else
    {
        cout << "Nao sao Multiplos";
    }

    cout << '\n';

    return 0;
}
