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

    string guest;
    string host;
    string letters;

    cin >> guest >> host >> letters;

    string names {guest + host};

    sort(names.begin(),   names.end());
    sort(letters.begin(), letters.end());

    cout << (names == letters ? "YES" : "NO") << '\n';

    return 0;
}
