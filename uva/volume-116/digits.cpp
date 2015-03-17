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

    for (string number; getline(cin, number) && number != "END"; )
    {
        unsigned int index {1};

        while (number != "1")
        {
            number = to_string(number.size());
            ++index;
        }

        cout << index << '\n';
    }

    return 0;
}
