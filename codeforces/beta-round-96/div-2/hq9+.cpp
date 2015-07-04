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

    string program;
    cin >> program;

    if (program.find('H') != string::npos ||
        program.find('Q') != string::npos ||
        program.find('9') != string::npos)
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
