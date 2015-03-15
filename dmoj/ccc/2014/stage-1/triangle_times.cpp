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

    unsigned int alpha;
    unsigned int beta;
    unsigned int gamma;

    cin >> alpha >> beta >> gamma;

    if (alpha + beta + gamma != 180)
    {
        cout << "Error";
    }
    else if (alpha == beta && beta == gamma)
    {
        cout << "Equilateral";
    }
    else if (alpha == beta || alpha == gamma || beta == gamma)
    {
        cout << "Isosceles";
    }
    else
    {
        cout << "Scalene";
    }

    cout << '\n';

    return 0;
}
