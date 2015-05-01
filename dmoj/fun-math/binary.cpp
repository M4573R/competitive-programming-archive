#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

constexpr unsigned int group_size {4};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

string to_binary(unsigned int number)
{
    if (number == 0)
    {
        return "0";
    }

    string binary;

    for (unsigned int i {number}; i > 0; i /= 2)
    {
        binary += '0' + i % 2;
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

string pad(const string& binary)
{
    if (binary.size() % group_size)
    {
        return string(group_size - binary.size() % group_size, '0') + binary;
    }

    return binary;
}

int main()
{
    use_io_optimizations();

    unsigned int numbers;
    cin >> numbers;

    for (unsigned int i {0}; i < numbers; ++i)
    {
        unsigned int number;
        cin >> number;

        string binary {pad(to_binary(number))};

        for (unsigned int j {0}; j < binary.size(); j += group_size)
        {
            if (j != 0)
            {
                cout << ' ';
            }

            cout << binary.substr(j, group_size);
        }

        cout << '\n';
    }

    return 0;
}
