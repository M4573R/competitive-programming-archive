#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<unsigned int, string> destinations {
    {61, "Brasilia"},
    {71, "Salvador"},
    {11, "Sao Paulo"},
    {21, "Rio de Janeiro"},
    {32, "Juiz de Fora"},
    {19, "Campinas"},
    {27, "Vitoria"},
    {31, "Belo Horizonte"}
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int code;
    cin >> code;

    if (destinations.count(code))
    {
        cout << destinations.at(code);
    }
    else
    {
        cout << "DDD nao cadastrado";
    }

    cout << '\n';

    return 0;
}
