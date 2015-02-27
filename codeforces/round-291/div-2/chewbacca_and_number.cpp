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

    for (auto& digit : number)
    {
        if (digit > '5')
        {
            digit = '9' - digit + '0';
        }
    }

    if (number.front() == '0')
    {
        number.front() = '9';
    }

    cout << number << '\n';

    return 0;
}
