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

    unsigned int banknotes;
    cin >> banknotes;

    unsigned int candidate  {0};
    unsigned int confidence {0};

    for (unsigned int i {0}; i < banknotes; ++i)
    {
        unsigned int banknote;
        cin >> banknote;

        if (confidence == 0)
        {
            candidate  = banknote;
            confidence = 1;
        }
        else if (candidate == banknote)
        {
            ++confidence;
        }
        else
        {
            --confidence;
        }
    }

    cout << candidate << '\n';

    return 0;
}
