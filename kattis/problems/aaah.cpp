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

    string actual;
    string required;

    cin >> actual >> required;

    cout << (actual.size() < required.size() ? "no" : "go") << '\n';

    return 0;
}
