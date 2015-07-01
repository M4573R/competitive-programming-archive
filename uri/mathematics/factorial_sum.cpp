#include <iostream>
#include <vector>

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

    vector<long long> factorials(21);

    factorials[0] = 1;

    for (unsigned int i {1}; i <= 20; ++i)
    {
        factorials[i] = factorials[i - 1] * i;
    }

    for (unsigned int first, second; cin >> first >> second; )
    {
        cout << factorials[first] + factorials[second] << '\n';
    }

    return 0;
}
