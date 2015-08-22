#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> factorial(unsigned int number)
{
    vector<unsigned int> digits {1};

    for (unsigned int i {2}; i <= number; ++i)
    {
        unsigned int carry {0};

        for (auto& digit : digits)
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int number;
        cin >> number;

        for (auto digit : factorial(number))
        {
            cout << digit;
        }

        cout << '\n';
    }

    return 0;
}
