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

    int right_side {0};
    cin >> right_side;

    for (char operation; cin >> operation && operation != '='; )
    {
        unsigned int term;
        cin >> term;

        switch (operation)
        {
        case 'P':
            right_side += term;
            break;

        case 'M':
            right_side -= term;
            break;
        }
    }

    cout << right_side << '\n';

    return 0;
}
