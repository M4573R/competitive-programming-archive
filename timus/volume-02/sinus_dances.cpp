#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void sequence_a(unsigned int index, unsigned int argument)
{
    cout << "sin(" << argument;

    if (index > 1)
    {
        cout << (argument % 2 == 0 ? '+' : '-');
        sequence_a(index - 1, argument + 1);
    }

    cout << ')';
}

void sequence_a(unsigned int index)
{
    sequence_a(index, 1);
}

void sequence_s(unsigned int index, unsigned int argument)
{
    if (index > 1)
    {
        cout << '(';
        sequence_s(index - 1, argument + 1);
        cout << ')';
    }

    sequence_a(index);
    cout << '+' << argument;
}

void sequence_s(unsigned int index)
{
    sequence_s(index, 1);
}

int main()
{
    use_io_optimizations();

    unsigned int index;
    cin >> index;

    sequence_s(index);

    cout << '\n';

    return 0;
}
