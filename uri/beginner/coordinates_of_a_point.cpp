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

    double x;
    double y;

    cin >> x >> y;

    if (x == 0 && y == 0)
    {
        cout << "Origem";
    }
    else if (x == 0)
    {
        cout << "Eixo Y";
    }
    else if (y == 0)
    {
        cout << "Eixo X";
    }
    else if (x > 0 && y > 0)
    {
        cout << "Q1";
    }
    else if (x < 0 && y > 0)
    {
        cout << "Q2";
    }
    else if (x < 0 && y < 0)
    {
        cout << "Q3";
    }
    else
    {
        cout << "Q4";
    }

    cout << '\n';

    return 0;
}
