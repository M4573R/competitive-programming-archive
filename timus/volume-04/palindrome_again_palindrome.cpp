#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

constexpr long long base   {5557};
constexpr long long modulo {799853};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long exponentiate(long long base, long long exponent, long long modulo)
{
    long long result    {1};
    long long aggregate {base};

    while (exponent > 0)
    {
        if (exponent % 2 != 0)
        {
            result = (result * aggregate) % modulo;
        }

        aggregate = (aggregate * aggregate) % modulo;

        exponent /= 2;
    }

    return result;
}

string shortest_palindrome(const string& prefix)
{
    long long exponent_a {exponentiate(base, prefix.size() - 1, modulo)};
    long long exponent_b {exponentiate(base, modulo - 2, modulo)};

    long long straight_hash {0};
    long long reversed_hash {0};

    for (string::size_type i {0}; i < prefix.size(); ++i)
    {
        straight_hash = (straight_hash * base % modulo + prefix[i]) % modulo;
        reversed_hash = (reversed_hash * base % modulo +
                         prefix[prefix.size() - 1 - i]) % modulo;
    }

    for (string::size_type i {0}; i < prefix.size(); ++i)
    {
        if (i != 0 && straight_hash == reversed_hash)
        {
            string suffix {prefix.substr(0, i)};
            reverse(suffix.begin(), suffix.end());

            return prefix + suffix;
        }

        straight_hash -= (exponent_a * prefix[i]) % modulo;
        straight_hash  = (straight_hash + modulo) % modulo;

        exponent_a = (exponent_a * exponent_b) % modulo;

        reversed_hash -= prefix[i] % modulo;
        reversed_hash  = (reversed_hash + modulo) % modulo;
        reversed_hash  = (reversed_hash * exponent_b) % modulo;
    }
}

int main()
{
    use_io_optimizations();

    string prefix;
    cin >> prefix;

    if (prefix.size() == 1)
    {
        cout << prefix << prefix << '\n';
        return 0;
    }

    cout << shortest_palindrome(prefix) << '\n';

    return 0;
}
