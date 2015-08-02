#include <iostream>
#include <string>
#include <utility>

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

    string first;
    string second;

    cin >> first >> second;

    cout << first.size()   << ' '
         << second.size()  << '\n'
         << first + second << '\n';

    swap(first.front(), second.front());

    cout << first  << ' '
         << second << '\n';

    return 0;
}
