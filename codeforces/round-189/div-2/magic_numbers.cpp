#include <iostream>
#include <string>


using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_magical(const string& number)
{
    return (number.front()                 == '1'          &&
            number.find("444")             == string::npos &&
            number.find_first_not_of("14") == string::npos);
}

int main()
{
    use_io_optimizations();

    string number;
    cin >> number;

    cout << (is_magical(number) ? "YES" : "NO") << '\n';

    return 0;
}
