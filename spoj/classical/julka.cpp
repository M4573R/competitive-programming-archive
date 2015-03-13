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

struct BigInt
{
    vector<int> digits;

    void trim();
    int size() const;
};

void BigInt::trim()
{
    while (!digits.empty() && digits.back() == 0)
    {
        digits.pop_back();
    }
}

int BigInt::size() const
{
    return digits.size();
}

istream& operator>>(istream& in, BigInt& number)
{
    string as_string;
    in >> as_string;

    for (string::size_type i {as_string.size()}; i-- > 0; )
    {
        number.digits.push_back(as_string[i] - '0');
    }

    return in;
}

ostream& operator<<(ostream& out, const BigInt& number)
{
    for (int i {number.size() - 1}; i >= 0; --i)
    {
        out << number.digits[i];
    }

    return out;
}

BigInt operator+(const BigInt& left, const BigInt& right)
{
    BigInt sum = left;

    int longest {max(left.size(), right.size())};

    for (int i {0}, carry {0}; i < longest || carry; ++i)
    {
        if (i == sum.size())
        {
            sum.digits.push_back(0);
        }

        sum.digits[i] += carry;

        if (i < right.size())
        {
            sum.digits[i] += right.digits[i];
        }

        carry = (sum.digits[i] >= 10);

        if (carry)
        {
            sum.digits[i] -= 10;
        }
    }

    return sum;
}

BigInt operator-(const BigInt& left, const BigInt& right)
{
    BigInt difference = left;

    for (int i {0}, carry {0}; i < right.size() || carry; ++i)
    {
        difference.digits[i] -= carry;

        if (i < right.size())
        {
            difference.digits[i] -= right.digits[i];
        }

        carry = (difference.digits[i] < 0);

        if (carry)
        {
            difference.digits[i] += 10;
        }
    }

    difference.trim();

    return difference;
}

BigInt operator/(const BigInt& left, unsigned int right)
{
    BigInt quotient = left;

    int remainder {0};

    for (int i {quotient.size() - 1}; i >= 0; --i)
    {
        remainder *= 10;
        remainder += quotient.digits[i];

        quotient.digits[i] = remainder / right;

        remainder %= right;
    }

    quotient.trim();

    return quotient;
}

int main()
{
    use_io_optimizations();

    for (unsigned int i {0}; i < 10; ++i)
    {
        BigInt total;
        BigInt more;

        cin >> total >> more;

        BigInt natalia = (total - more) / 2;
        BigInt klaudia = natalia + more;

        cout << klaudia << '\n'
             << natalia << '\n';
    }

    return 0;
}
