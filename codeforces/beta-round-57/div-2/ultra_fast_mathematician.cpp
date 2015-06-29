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

    string first;
    string second;

    cin >> first >> second;

    for (string::size_type i {0}; i < first.size(); ++i)
    {
        if (first[i] == second[i])
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
    }

    cout << '\n';

    return 0;
}
