#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string stones;
    cin >> stones;

    unsigned int digit_sum {0};

    for (auto digit : stones)
    {
        digit_sum += digit - '0';
    }

    if (digit_sum % 3 == 0)
    {
        cout << 2 << '\n';
    }
    else
    {
        cout << 1             << '\n'
             << digit_sum % 3 << '\n';
    }

    return 0;
}
