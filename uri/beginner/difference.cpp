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

    int first;
    int second;
    int third;
    int fourth;

    cin >> first >> second >> third >> fourth;

    cout << "DIFERENCA = " << first * second - third * fourth << '\n';

    return 0;
}
