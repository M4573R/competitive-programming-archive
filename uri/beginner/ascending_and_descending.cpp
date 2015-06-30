#include <iostream>

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

    for (int first, second; cin >> first >> second && first != second; )
    {
        cout << (first < second ? "Crescente" : "Decrescente") << '\n';
    }

    return 0;
}
