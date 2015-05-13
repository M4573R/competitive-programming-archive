#include <iostream>
#include <sstream>
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

    string south;
    string north;

    getline(cin, south);
    getline(cin, north);

    unsigned int seconds {0};

    string::size_type i {0};
    string::size_type j {0};

    while (i < south.size() && j < north.size())
    {
        if (south[i] == 'L' && north[j] != 'L')
        {
            ++j;
        }
        else if (south[i] != 'L' && north[j] == 'L')
        {
            ++i;
        }
        else
        {
            ++i;
            ++j;
        }

        ++seconds;
    }

    seconds += south.size() - i;
    seconds += north.size() - j;

    cout << seconds << '\n';

    return 0;
}
