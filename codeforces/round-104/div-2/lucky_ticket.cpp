#include <iostream>
#include <numeric>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_lucky_number(const string& number)
{
    return number.find_first_not_of("47") == string::npos;
}

bool is_lucky_ticket(const string& ticket)
{
    if (is_lucky_number(ticket))
    {
        auto middle = ticket.size() / 2;

        return (accumulate(ticket.cbegin(), ticket.cbegin() + middle, 0) ==
                accumulate(ticket.cbegin() + middle, ticket.cend(), 0));
    }

    return false;
}

int main()
{
    use_io_optimizations();

    unsigned int length;
    cin >> length;

    string ticket;
    cin >> ticket;

    cout << (is_lucky_ticket(ticket) ? "YES" : "NO") << '\n';

    return 0;
}
