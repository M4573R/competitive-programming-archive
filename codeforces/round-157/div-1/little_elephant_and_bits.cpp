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

    auto first_zero = number.find('0');

    if (first_zero != string::npos)
    {
        number.erase(first_zero, 1);
        cout << number << '\n';
    }
    else
    {
        number.pop_back();
        cout << number << '\n';
    }

    return 0;
}
