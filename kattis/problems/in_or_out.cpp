#include <cmath>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Complex
{
public:
    Complex():
        real      {0},
        imaginary {0}
    { }

    double modulus() const
    {
        return sqrt(real * real + imaginary * imaginary);
    }

    Complex operator+(const Complex& other) const
    {
        Complex sum;

        sum.real      = real + other.real;
        sum.imaginary = imaginary + other.imaginary;

        return sum;
    }

    Complex operator*(const Complex& other) const
    {
        Complex product;

        product.real      = real * other.real - imaginary * other.imaginary;
        product.imaginary = real * other.imaginary + imaginary * other.real;

        return product;
    }

    friend
    istream& operator>>(istream&, Complex&);

private:
    double real;
    double imaginary;
};

istream& operator>>(istream& in, Complex& number)
{
    return in >> number.real >> number.imaginary;
}

int main()
{
    use_io_optimizations();

    Complex number;
    unsigned int iterations;

    for (unsigned int test {1}; cin >> number >> iterations; ++test)
    {
        Complex current;
        bool diverges {false};

        for (unsigned int i {0}; i < iterations && !diverges; ++i)
        {
            current = current * current + number;

            if (current.modulus() > 2)
            {
                diverges = true;
            }
        }

        cout << "Case " << test << ": " << (diverges ? "OUT" : "IN") << '\n';
    }

    return 0;
}
