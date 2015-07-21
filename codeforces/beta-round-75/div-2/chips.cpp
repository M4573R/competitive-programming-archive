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

    unsigned int walruses;
    unsigned int chips;

    cin >> walruses >> chips;

    for (unsigned int i {0}; i < chips; i = (i + 1) % walruses)
    {
        chips -= i + 1;
    }

    cout << chips << '\n';

    return 0;
}
