#include <algorithm>
#include <iostream>
#include <string>
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
    BigInt():
        digits {0}
    { }

    BigInt& operator+=(const BigInt& other)
    {
        unsigned int length {max(digits.size(), other.digits.size())};

        for (unsigned int i {0}, carry {0}; i < length || carry; ++i)
        {
            if (i == digits.size())
            {
                digits.push_back(0);
            }

            digits[i] += carry;

            if (i < other.digits.size())
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

    friend
    istream& operator>>(istream&, BigInt&);

    friend
    ostream& operator<<(ostream&, const BigInt&);

private:
    vector<unsigned int> digits;
};

istream& operator>>(istream& in, BigInt& number)
{
    string as_string;
    in >> as_string;

    number.digits.clear();

    for (auto i = as_string.crbegin(); i != as_string.crend(); ++i)
    {
        number.digits.push_back(*i - '0');
    }

    return in;
}

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

    BigInt sum;

    for (BigInt number; cin >> number; )
    {
        sum += number;
    }

    cout << sum << '\n';

    return 0;
}
