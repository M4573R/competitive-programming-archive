#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int numbers_count;
    cin >> numbers_count;

    unsigned int previous;
    cin >> previous;

    unsigned int quantity {1};

    for (unsigned int i {1}; i < numbers_count; ++i)
    {
        unsigned int next;
        cin >> next;

        if (next == previous)
        {
            ++quantity;
        }
        else
        {
            cout << quantity << ' ' << previous << ' ';

            previous = next;
            quantity = 1;
        }
    }

    cout << quantity << ' ' << previous << '\n';

    return 0;
}
