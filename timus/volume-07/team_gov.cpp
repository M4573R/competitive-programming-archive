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

    unsigned long long charge;
    unsigned int visits;

    cin >> charge >> visits;

    unsigned int       visit {0};
    unsigned long long paid  {0};

    while (visit < visits && paid <= 3 * charge)
    {
        unsigned int check;
        cin >> check;

        paid  += check;
        visit += 1;
    }

    if (paid <= 3 * charge)
    {
        cout << "Team.GOV!\n";
    }
    else
    {
        cout << "Free after " << visit << " times.\n";
    }

    return 0;
}
