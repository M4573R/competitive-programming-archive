#include <algorithm>
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

    unsigned int length;
    cin >> length;

    string sequence;
    cin >> sequence;

    cout << abs(count(sequence.cbegin(), sequence.cend(), '0') -
                count(sequence.cbegin(), sequence.cend(), '1'))
         << '\n';

    return 0;
}
