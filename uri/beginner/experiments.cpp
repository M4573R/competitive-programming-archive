#include <iomanip>
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

    cout << fixed << setprecision(2);

    unsigned int experiments;
    cin >> experiments;

    unsigned int rabbits {0};
    unsigned int rats    {0};
    unsigned int frogs   {0};

    for (unsigned int i {0}; i < experiments; ++i)
    {
        unsigned int count;
        char type;

        cin >> count >> type;

        if (type == 'C')
        {
            rabbits += count;
        }
        else if (type == 'R')
        {
            rats += count;
        }
        else if (type == 'S')
        {
            frogs += count;
        }
    }

    unsigned int total {rabbits + rats + frogs};

    cout << "Total: "            << total   << " cobaias\n"
         << "Total de coelhos: " << rabbits << '\n'
         << "Total de ratos: "   << rats    << '\n'
         << "Total de sapos: "   << frogs   << '\n';

    cout << "Percentual de coelhos: " << 100.0 * rabbits / total << " %\n"
         << "Percentual de ratos: "   << 100.0 * rats / total    << " %\n"
         << "Percentual de sapos: "   << 100.0 * frogs / total   << " %\n";

    return 0;
}
