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

    for (auto digit = number.crbegin(); digit != number.crend(); ++digit)
    {
        cout << *digit << '\n';
    }

    return 0;
}
