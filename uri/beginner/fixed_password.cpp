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

    for (int password; cin >> password && password != 2002; )
    {
        cout << "Senha Invalida\n";
    }

    cout << "Acesso Permitido\n";

    return 0;
}
