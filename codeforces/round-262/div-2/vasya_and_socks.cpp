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

    unsigned int socks;
    unsigned int days_to_new_pair;

    cin >> socks >> days_to_new_pair;

    unsigned int past_days {socks};

    for (unsigned int days {past_days}; days >= days_to_new_pair; )
    {
        unsigned int new_pairs {days / days_to_new_pair};

        days %= days_to_new_pair;
        days += new_pairs;

        past_days += new_pairs;
    }

    cout << past_days << '\n';

    return 0;
}
