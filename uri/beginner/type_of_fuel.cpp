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

    unsigned int alcohol  {0};
    unsigned int gasoline {0};
    unsigned int diesel   {0};

    for (unsigned int type; cin >> type && type != 4; )
    {
        if (type == 1)
        {
            ++alcohol;
        }
        else if (type == 2)
        {
            ++gasoline;
        }
        else if (type == 3)
        {
            ++diesel;
        }
    }

    cout << "MUITO OBRIGADO\n"
         << "Alcool: "   << alcohol  << '\n'
         << "Gasolina: " << gasoline << '\n'
         << "Diesel: "   << diesel   << '\n';

    return 0;
}
