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

    for (int x, y; cin >> x >> y && x != 0 && y != 0; )
    {
        if (x > 0 && y > 0)
        {
            cout << "primeiro";
        }
        else if (x < 0 && y > 0)
        {
            cout << "segundo";
        }
        else if (x < 0 && y < 0)
        {
            cout << "terceiro";
        }
        else
        {
            cout << "quarto";
        }

        cout << '\n';
    }

    return 0;
}
