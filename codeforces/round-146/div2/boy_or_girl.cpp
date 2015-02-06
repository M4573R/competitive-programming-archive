#include <iostream>
#include <set>
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

    string username;
    cin >> username;

    set<char> characters(username.cbegin(), username.cend());

    cout << (characters.size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!") << '\n';

    return 0;
}
