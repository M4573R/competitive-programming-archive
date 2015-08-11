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

    unsigned int cars;
    cin >> cars;

    unsigned int red;
    unsigned int white;
    unsigned int black;
    unsigned int yellow;
    unsigned int green;

    cin >> red >> white >> black >> yellow >> green;

    unsigned int needed {(red    + 3) / 4 +
                         (white  + 4) / 5 +
                         (black  + 3) / 4 +
                         (yellow + 2) / 3 +
                         (green  + 5) / 6};

    cout << (needed < cars ? cars - needed : 0) << '\n';

    return 0;
}
