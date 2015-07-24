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

    string sequence;

    for (unsigned int i {0}; i < 333333; ++i)
    {
        sequence += 'a' + i / 676 % 26;
        sequence += 'a' + i / 26  % 26;
        sequence += 'a' + i       % 26;
    }

    sequence += 'a';

    cout << sequence << '\n';

    return 0;
}
