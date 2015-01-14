#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline bool is_lucky(unsigned int ticket)
{
    return (ticket / 100000   + ticket / 10000 % 10 + ticket / 1000 % 10 ==
            ticket / 100 % 10 + ticket / 10 % 10    + ticket % 10);
}

int main()
{
    use_io_optimizations();

    unsigned int ticket;
    cin >> ticket;

    if (is_lucky(ticket - 1) || is_lucky(ticket + 1))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    cout << '\n';

    return 0;
}
