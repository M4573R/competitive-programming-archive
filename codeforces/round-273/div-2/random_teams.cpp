#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
unsigned long long pairs(unsigned long long people)
{
    return people * (people - 1) / 2;
}

int main()
{
    use_io_optimizations();

    unsigned long long participants;
    unsigned long long teams;

    cin >> participants >> teams;

    unsigned long long minimum {
        (teams - participants % teams) * pairs(participants / teams) +
        (participants % teams)         * pairs(participants / teams + 1)
    };

    unsigned long long maximum {
        pairs(participants - teams + 1)
    };

    cout << minimum << ' ' << maximum << '\n';

    return 0;
}
