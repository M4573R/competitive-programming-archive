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

    unsigned int antonia_score {100};
    unsigned int david_score   {100};

    unsigned int rounds;
    cin >> rounds;

    for (unsigned int round {0}; round < rounds; ++round)
    {
        unsigned int antonia_roll;
        unsigned int david_roll;

        cin >> antonia_roll >> david_roll;

        if (antonia_roll < david_roll)
        {
            antonia_score -= david_roll;
        }
        else if (antonia_roll > david_roll)
        {
            david_score -= antonia_roll;
        }
    }

    cout << antonia_score << '\n'
         << david_score   << '\n';

    return 0;
}
