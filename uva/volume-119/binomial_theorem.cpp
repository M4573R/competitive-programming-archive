#include <iostream>
#include <sstream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned long long combinations(unsigned int n, unsigned int k)
{
    unsigned long long result = 1;

    for (unsigned int i {0}; i < k; ++i)
    {
        result *= n - i;
        result /= i + 1;
    }

    return result;
}

string power_expansion(const string& left,
                       const string& right,
                       unsigned int power)
{
    ostringstream expansion;

    for (unsigned int i {power + 1}; i-- > 0;)
    {
        unsigned long long coefitient {combinations(power, i)};

        unsigned int left_exponent    {i};
        unsigned int right_exponent   {power - i};

        if (coefitient != 1)
        {
            expansion << coefitient << '*';
        }

        if (left_exponent != 0)
        {
            expansion << left;

            if (left_exponent > 1)
            {
                expansion << '^' << left_exponent;
            }
        }

        if (right_exponent != 0)
        {
            if (left_exponent != 0)
            {
                expansion << '*';
            }

            expansion << right;

            if (right_exponent > 1)
            {
                expansion << '^' << right_exponent;
            }
        }

        if (i > 0)
        {
            expansion << '+';
        }
    }

    return expansion.str();
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        string left;
        string right;

        cin.get();
        cin.get();

        getline(cin, left,  '+');
        getline(cin, right, ')');

        cin.get();

        unsigned int power;
        cin >> power;

        cout << "Case " << i + 1 << ": ";
        cout << power_expansion(left, right, power) << '\n';
    }

    return 0;
}
