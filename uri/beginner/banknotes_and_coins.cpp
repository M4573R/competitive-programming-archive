#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const vector<double> notes {100, 50, 20, 10, 5, 2,};
const vector<double> coins {1, 0.5, 0.25, 0.1, 0.05, 0.01};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    double money;
    cin >> money;

    cout << "NOTAS:\n";

    for (auto note : notes)
    {
        unsigned int count = money / note;

        cout << count << " nota(s) de R$ " << note << '\n';
        money -= note * count;
    }

    cout << "MOEDAS:\n";

    for (auto coin : coins)
    {
        unsigned int count = money / coin;

        cout << count << " moeda(s) de R$ " << coin << '\n';
        money -= coin * count;
    }

    return 0;
}
