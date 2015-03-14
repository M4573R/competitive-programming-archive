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

    unsigned int tines_length;
    unsigned int tines_spacing;
    unsigned int handle_length;

    cin >> tines_length >> tines_spacing >> handle_length;

    string tines_line  {'*' + string(tines_spacing, ' ') +
                        '*' + string(tines_spacing, ' ') +
                        '*'};

    string handle_line {string(tines_spacing + 1, ' ') + '*'};

    for (unsigned int i {0}; i < tines_length; ++i)
    {
        cout << tines_line << '\n';
    }

    cout << string(2 * tines_spacing + 3, '*') << '\n';

    for (unsigned int i {0}; i < handle_length; ++i)
    {
        cout << handle_line << '\n';
    }

    return 0;
}
