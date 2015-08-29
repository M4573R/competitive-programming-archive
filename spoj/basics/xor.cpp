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

    bool first;
    bool second;

    cin >> first >> second;

    cout << (first ^ second) << '\n';

    return 0;
}
