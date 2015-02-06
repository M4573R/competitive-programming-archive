#include <iostream>
#include <string>

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

    string number;
    cin >> number;

    unsigned int lucky_digits {0};

    for (auto digit : number)
    {
        if (digit == '4' || digit == '7')
        {
            ++lucky_digits;
        }
    }

    cout << (lucky_digits == 4 || lucky_digits == 7 ? "YES" : "NO") << '\n';

    return 0;
}
