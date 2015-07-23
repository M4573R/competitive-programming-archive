#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    vector<unsigned int> good_per_digit {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

    unsigned int number;
    cin >> number;

    cout << good_per_digit[number / 10] * good_per_digit[number % 10] << '\n';

    return 0;
}
