#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<unsigned int> reversed_factorial_digits(unsigned int n)
{
    vector<unsigned int> digits;
    digits.push_back(1);

    for (unsigned int i = 1; i <= n; ++i)
    {
        unsigned int carry = 0;

        for (vector<unsigned int>::iterator digit = digits.begin();
             digit != digits.end();
             ++digit)
        {
            unsigned int product = *digit * i + carry;

            *digit = product % 10;
            carry  = product / 10;
        }

        while (carry > 0)
        {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    return digits;
}

int main()
{
    use_io_optimizations();

    unsigned int input_size;
    cin >> input_size;

    for (unsigned int i = 0; i < input_size; ++i)
    {
        unsigned int n;
        cin >> n;

        vector<unsigned int> digits = reversed_factorial_digits(n);

        for (vector<unsigned int>::const_reverse_iterator digit = digits.rbegin();
             digit != digits.rend();
             ++digit)
        {
            cout << *digit;
        }

        cout << '\n';
    }

    return 0;
}
