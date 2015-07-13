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

    unsigned int bits;
    cin >> bits;

    string cell;
    cin >> cell;

    auto first_zero = cell.find('0');

    cout << (first_zero == string::npos ? bits : first_zero + 1) << '\n';

    return 0;
}
