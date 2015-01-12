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

    string ciphertext;
    string plaintext;

    cin >> ciphertext;

    for (auto symbol : ciphertext)
    {
        if (!plaintext.empty() && symbol == plaintext.back())
        {
            plaintext.pop_back();
        }
        else
        {
            plaintext.push_back(symbol);
        }
    }

    cout << plaintext << '\n';

    return 0;
}
