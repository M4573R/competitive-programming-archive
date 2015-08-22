#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> factorial_digits(unsigned int n)
{
    vector<unsigned int> digits {1};

    for (unsigned int i {1}; i <= n; ++i)
    {
        unsigned int carry {0};

        for (unsigned int& digit : digits)
        {
            unsigned int product {digit * i + carry};

            digit = product % 10;
            carry = product / 10;
        }

        while (carry > 0)
        {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(digits.begin(), digits.end());

    return digits;
}

int main()
{
    use_io_optimizations();

    unsigned int input_size;
    cin >> input_size;

    for (unsigned int i {0}; i < input_size; ++i)
    {
        unsigned int n;
        cin >> n;

        for (unsigned int digit : factorial_digits(n))
        {
            cout << digit;
        }

        cout << '\n';
    }

    return 0;
}
