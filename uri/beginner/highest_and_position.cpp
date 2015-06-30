#include <iostream>

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

    unsigned int maximum  {0};
    unsigned int position {0};

    for (unsigned int i {1}; i <= 100; ++i)
    {
        unsigned int number;
        cin >> number;

        if (number > maximum)
        {
            maximum  = number;
            position = i;
        }
    }

    cout << maximum  << '\n'
         << position << '\n';

    return 0;
}
