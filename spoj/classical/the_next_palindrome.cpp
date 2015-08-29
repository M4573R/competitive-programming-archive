#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
string all_nines_case(const string& number)
{
    return '1' + string(number.size() - 1, '0') + '1';
}

string not_all_nines_case(string number)
{
    ++number.back();

    for (string::size_type i {0}; i < number.size() / 2; ++i)
    {
        if (number[i] < number[number.size() - 1 - i])
        {
            string::size_type j {number.size() - 1 - i - 1};

            while (number[j] == '9')
            {
                number[j--] = '0';
            }

            ++number[j];
        }

        number[number.size() - 1 - i] = number[i];
    }

    return number;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string number;
        cin >> number;

        if (number.find_first_not_of("9") == string::npos)
        {
            cout << all_nines_case(number) << '\n';
        }
        else
        {
            cout << not_all_nines_case(number) << '\n';
        }
    }

    return 0;
}
