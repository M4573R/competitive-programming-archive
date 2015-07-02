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

    string players;
    cin >> players;

    if (players.find("0000000") != string::npos ||
        players.find("1111111") != string::npos)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    cout << '\n';

    return 0;
}
