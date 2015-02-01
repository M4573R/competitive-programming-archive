#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

string to_binary(unsigned int number, unsigned int length)
{
    string binary;

    for (unsigned int i = length; i-- > 0; )
    {
        binary += (number & (1 << i) ? '1' : '0');
    }

    return binary;
}

string binary_palindromic_base(unsigned int number)
{
    if (number == 0)
    {
        return "0";
    }
    else if (number == 1)
    {
        return "1";
    }

    number -= 2;

    for (unsigned int length = 2, half_bits = 0; ; ++length)
    {
        if (length % 2)
        {
            ++half_bits;
        }

        unsigned int palindromes = 1 << half_bits;

        if (number < palindromes)
        {
            string binary   = '1' + to_binary(number, half_bits);
            string reversed = binary;

            reverse(reversed.begin(), reversed.end());

            return binary + (length % 2 ? reversed.substr(1) : reversed);
        }

        number -= palindromes;
    }
}

int main()
{
    use_io_optimizations();

    for (unsigned int number; cin >> number && number != -1; )
    {
        cout << binary_palindromic_base(number) << '\n';
    }

    return 0;
}
