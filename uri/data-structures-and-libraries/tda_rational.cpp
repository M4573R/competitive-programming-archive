#include <cstdlib>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int gcd(int left, int right)
{
    if (right == 0)
    {
        if (left == 0)
        {
            return 1;
        }

        return left;
    }

    for (int remainder {left % right}; remainder = left % right; )
    {
        left  = right;
        right = remainder;
    }

    return right;
}

struct Rational
{
    int numerator;
    int denominator;

    Rational(int numerator = 0, int denominator = 0):
        numerator(numerator),
        denominator(denominator)
    { }

    int sign() const
    {
        long long product {numerator * denominator};

        return product < 0 ? -1:
               product > 0 ? +1:
                              0;
    }

    Rational simplify() const
    {
        int divisor {gcd(numerator, denominator)};

        return {numerator / divisor, denominator / divisor};
    }
};

Rational operator+(const Rational& left, const Rational& right)
{
    return {(left.numerator  * right.denominator +
             right.numerator * left.denominator),
            left.denominator * right.denominator};
}

Rational operator-(const Rational& left, const Rational& right)
{
    return {(left.numerator  * right.denominator -
             right.numerator * left.denominator),
            left.denominator * right.denominator};
}

Rational operator*(const Rational& left, const Rational& right)
{
    return {left.numerator   * right.numerator,
            left.denominator * right.denominator};
}

Rational operator/(const Rational& left, const Rational& right)
{
    return {left.numerator  * right.denominator,
            right.numerator * left.denominator};
}

istream& operator>>(istream& in, Rational& number)
{
    char delimiter;

    in >> number.numerator >> delimiter >> number.denominator;

    return in;
}

ostream& operator<<(ostream& out, const Rational& number)
{
    int numerator   {abs(number.numerator) * number.sign()};
    int denominator {abs(number.denominator)};

    out << numerator << '/' << denominator;

    return out;
}

Rational compute(const Rational& left, char operation, const Rational& right)
{
    switch (operation)
    {
    case '+':
        return left + right;

    case '-':
        return left - right;

    case '*':
        return left * right;

    case '/':
        return left / right;
    }

    return {};
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        char operation;

        Rational left;
        Rational right;

        cin >> left >> operation >> right;

        Rational result {compute(left, operation, right)};

        cout << result << " = " << result.simplify() << '\n';
    }

    return 0;
}
