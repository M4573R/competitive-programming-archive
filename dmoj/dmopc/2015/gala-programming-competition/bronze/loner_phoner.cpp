#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int numbers;
    cin >> numbers;

    for (unsigned int i {0}; i < numbers; ++i)
    {
        string number;
        cin >> number;

        if (number.size()        != 10    ||
            (number.substr(0, 3) != "416" &&
             number.substr(0, 3) != "647"))
        {
            cout << "not a phone number\n";
        }
        else
        {
            number.insert(6, "-");
            number.insert(3, "-");
            number.insert(3, ")");
            number.insert(0, "(");

            cout << number << '\n';
        }
    }

    return 0;
}
