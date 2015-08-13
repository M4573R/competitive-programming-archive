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
        sign {1}
    { }

    BigInt operator-() const
    {
        BigInt opposite {*this};
        opposite.sign = -opposite.sign;

        return opposite;
    }

    BigInt operator+(const BigInt& other) const
    {
        if (sign == other.sign)
        {
            BigInt sum {*this};
            unsigned int length {max(sum.size(), other.size())};

            for (unsigned int i {0}, carry {0}; i < length || carry; ++i)
            {
                if (i == sum.size())
                {
                    sum.digits.push_back(0);
                }

                sum.digits[i] += carry;

                if (i < other.size())
                {
                    sum.digits[i] += other.digits[i];
                }

                carry = (sum.digits[i] >= 10);

                if (carry)
                {
                    sum.digits[i] -= 10;
                }
            }

            return sum;
        }

        return *this - (-other);
    }

    BigInt operator-(const BigInt& other) const
    {
        if (sign == other.sign)
        {
            if (abs() >= other.abs())
            {
                BigInt difference {*this};

                for (unsigned int i {0}, carry {0}; i < other.size() || carry; ++i)
                {
                    difference.digits[i] -= carry;

                    if (i < other.size())
                    {
                        difference.digits[i] -= other.digits[i];
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

            return -(other - *this);
        }

        return *this + (-other);
    }

    bool operator<(const BigInt& other) const
    {
        if (sign != other.sign)
        {
            return sign < other.sign;
        }

        if (size() != other.size())
        {
            return sign * size() < other.sign * other.size();
        }

        for (auto i = size(); i-- > 0; )
        {
            if (digits[i] != other.digits[i])
            {
                return sign * digits[i] < other.sign * other.digits[i];
            }
        }

        return false;
    }

    bool operator>=(const BigInt& other) const
    {
        return !(*this < other);
    }

    BigInt abs() const
    {
        BigInt abs_value {*this};
        abs_value.sign = 1;

        return abs_value;
    }

    unsigned int size() const
    {
        return digits.size();
    }

    friend
    istream& operator>>(istream&, BigInt&);

    friend
    ostream& operator<<(ostream&, const BigInt&);

private:
    int sign;
    vector<int> digits;

    void trim()
    {
        while (!digits.empty() && digits.back() == 0)
        {
            digits.pop_back();
        }

        if (digits.empty())
        {
            sign = 1;
        }
    }
};

istream& operator>>(istream& in, BigInt& number)
{
    string sequence;
    in >> sequence;

    for (auto i = sequence.crbegin(); i != sequence.crend(); ++i)
    {
        if (*i == '-')
        {
            number.sign = -number.sign;
        }
        else if (*i != '+')
        {
            number.digits.push_back(*i - '0');
        }
    }

    return in;
}

ostream& operator<<(ostream& out, const BigInt& number)
{
    if (number.sign == -1)
    {
        out << '-';
    }

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

    unsigned int problems;
    cin >> problems;

    for (unsigned int i {0}; i < problems; ++i)
    {
        BigInt left;
        BigInt right;

        cin >> left >> right;

        cout << left + right << '\n';
    }

    return 0;
}
