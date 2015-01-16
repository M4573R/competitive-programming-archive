#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string solution;

    while (getline(cin, solution))
    {
        cout << solution << '\n';
    }

    return 0;
}
