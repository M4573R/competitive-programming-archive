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

    vector<unsigned int> actual(3);
    vector<unsigned int> expected(3);

    cin >> actual[2]   >> actual[1]   >> actual[0]
        >> expected[2] >> expected[1] >> expected[0];

    if (actual <= expected)
    {
        cout << 0;
    }
    else if (actual[0] != expected[0])
    {
        cout << 10000;
    }
    else if (actual[1] != expected[1])
    {
        cout << 500 * (actual[1] - expected[1]);
    }
    else
    {
        cout << 15 * (actual[2] - expected[2]);
    }

    cout << '\n';

    return 0;
}
