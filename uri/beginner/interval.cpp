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

    double number;
    cin >> number;

    if (number < 0)
    {
        cout << "Fora de intervalo";
    }
    else if (number <= 25)
    {
        cout << "Intervalo [0,25]";
    }
    else if (number <= 50)
    {
        cout << "Intervalo (25,50]";
    }
    else if (number <= 75)
    {
        cout << "Intervalo (50,75]";
    }
    else if (number <= 100)
    {
        cout << "Intervalo (75,100]";
    }
    else
    {
        cout << "Fora de intervalo";
    }

    cout << '\n';

    return 0;
}
