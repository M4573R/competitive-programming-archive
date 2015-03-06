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

    unsigned int first;
    unsigned int second;

    cin >> first >> second;

    cout << (first % second == 0 ? "yes" : "no") << '\n';

    return 0;
}
