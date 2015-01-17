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

    unsigned int events;

    for (unsigned int test {1}; cin >> events && events != 0; ++test)
    {
        int balance {0};

        for (unsigned int i {0}; i < events; ++i)
        {
            unsigned int event;
            cin >> event;

            balance += (event == 0 ? -1 : 1);
        }

        cout << "Case " << test << ": " << balance << '\n';
    }

    return 0;
}
