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

    string cipher;
    cin >> cipher;

    cipher.insert(0, 1, 'a' + 5);

    for (string::size_type i {1}; i < cipher.length(); ++i)
    {
        cout << char('a' + (cipher[i] - cipher[i - 1] + 26) % 26);
    }

    return 0;
}
