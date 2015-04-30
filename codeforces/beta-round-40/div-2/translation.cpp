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

    string word;
    string translation;

    cin >> word >> translation;

    reverse(word.begin(), word.end());

    cout << (word == translation ? "YES" : "NO") << '\n';

    return 0;
}
