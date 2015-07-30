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

class BigInt
{
public:
    BigInt(unsigned int number = 0)
    {
        for (unsigned int i {number}; i > 0; i /= 10)
        {
            digits.push_back(i % 10);
        }
    }

    unsigned int size() const
    {
        return digits.size();
    }

    BigInt operator+=(const BigInt& other)
    {
        unsigned int length {max(size(), other.size())};

        for (unsigned int i {0}, carry {0}; i < length || carry; ++i)
        {
            if (i == size())
            {
                digits.push_back(0);
            }

            digits[i] += carry;

            if (i < other.size())
            {
                digits[i] += other.digits[i];
            }

            carry = (digits[i] >= 10);

            if (carry)
            {
                digits[i] -= 10;
            }
        }

        return *this;
    }

    BigInt operator*=(const BigInt& other)
    {
        BigInt product;

        for (unsigned int i {0}; i < size(); ++i)
        {
            BigInt summand;
            summand.digits.resize(i, 0);

            for (unsigned int j {0}, carry {0}; j < other.size() || carry; ++j)
            {
                if (j < other.size())
                {
                    carry += digits[i] * other.digits[j];
                }

                summand.digits.push_back(carry % 10);
                carry /= 10;
            }

            product += summand;
        }

        return *this = product;
    }

    friend
    ostream& operator<<(ostream&, const BigInt&);

private:
    vector<unsigned int> digits;
};

ostream& operator<<(ostream& out, const BigInt& number)
{
    for (auto i = number.digits.crbegin(); i != number.digits.crend(); ++i)
    {
        out << *i;
    }

    return out;
}

int main()
{
    use_io_optimizations();

    unsigned int number;
    cin >> number;

    BigInt factorial {1};

    for (unsigned int i {2}; i <= number; ++i)
    {
        factorial *= i;
    }

    cout << factorial << '\n';

    return 0;
}
