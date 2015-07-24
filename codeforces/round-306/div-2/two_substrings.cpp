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

    string sequence;
    cin >> sequence;

    auto first_ab = sequence.find("AB");
    auto last_ab  = sequence.rfind("AB");

    auto first_ba = sequence.find("BA");
    auto last_ba  = sequence.rfind("BA");

    if (first_ab != string::npos && first_ba != string::npos &&
        (first_ab + 1 < last_ba || first_ba + 1 < last_ab))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
