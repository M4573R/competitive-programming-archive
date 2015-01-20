#include <iostream>
#include <vector>

using namespace std;

const vector<unsigned int> bank_notes  {10, 50, 100, 500, 1000, 5000};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int money         {0};
    unsigned int min_bank_note {0};

    for (auto bank_note : bank_notes)
    {
        unsigned int count;
        cin >> count;

        money += count * bank_note;

        if (count != 0 && min_bank_note == 0)
        {
            min_bank_note = bank_note;
        }
    }

    unsigned int ticket_price;
    cin >> ticket_price;

    unsigned int min_tickets {(money - min_bank_note) / ticket_price + 1};
    unsigned int max_tickets {money / ticket_price};

    cout << max_tickets - min_tickets + 1 << '\n';

    for (unsigned int i {min_tickets}; i <= max_tickets; ++i)
    {
        cout << i;

        if (i < max_tickets)
        {
            cout << ' ';
        }
    }

    cout << '\n';

    return 0;
}
