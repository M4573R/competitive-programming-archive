#include <algorithm>
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

    string exponent;
    cin >> exponent;

    unsigned int last_two {
        stoi(exponent.substr(max(2u, exponent.size()) - 2, 2))
    };

    cout << (last_two % 4 == 0 ? 4 : 0) << '\n';

    return 0;
}
