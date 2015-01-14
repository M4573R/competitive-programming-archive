#include <algorithm>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int gcd(int a, int b)
{
    while (b > 0)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main()
{
    use_io_optimizations();

    int simons;
    int antisimons;
    int stones;

    cin >> simons >> antisimons >> stones;

    while (true)
    {
        stones -= gcd(simons, stones);

        if (stones < 0)
        {
            cout << 1;
            break;
        }

        stones -= gcd(antisimons, stones);

        if (stones < 0)
        {
            cout << 0;
            break;
        }
    }

    cout << '\n';

    return 0;
}
