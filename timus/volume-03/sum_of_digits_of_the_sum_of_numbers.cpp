#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class BigInt
{
public:
    BigInt(unsigned int number)
    {
        for (unsigned int i {number}; i > 0; i /= 10)
        {
            digits.push_back(i % 10);
        }
    }

    BigInt& operator*=(unsigned int multiplier)
    {
        unsigned int carry {0};

        for (auto& digit : digits)
        {
            unsigned int product {digit * multiplier + carry};

            digit = product % 10;
            carry = product / 10;
        }

        while (carry > 0)
        {
            digits.push_back(carry % 10);
            carry /= 10;
        }

        return *this;
    }

    friend
    ostream& operator<<(ostream&, const BigInt&);

private:
    vector<unsigned int> digits;
};

ostream& operator<<(ostream& out, const BigInt& number)
{
    if (number.digits.empty())
    {
        out << 0;
    }

    for (auto i = number.digits.crbegin(); i != number.digits.crend(); ++i)
    {
        out << *i;
    }

    return out;
}

int main()
{
    use_io_optimizations();

    unsigned int digits;
    cin >> digits;

    BigInt pairs {1};

    for (unsigned int i {0}; i < digits - 1; ++i)
    {
        pairs *= 55;
    }

    pairs *= 36;

    cout << pairs << '\n';

    return 0;
}
