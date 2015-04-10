#include <iostream>
#include <vector>

using namespace std;

const vector<unsigned int> banknotes {100, 50, 20, 10, 5, 2, 1};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int money;
    cin >> money;

    cout << money << '\n';

    for (auto banknote : banknotes)
    {
        cout << money / banknote << " nota(s) de R$ " << banknote << ",00\n";
        money %= banknote;
    }

    return 0;
}
