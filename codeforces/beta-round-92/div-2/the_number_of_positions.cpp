#include <algorithm>
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

    unsigned int people;
    unsigned int front;
    unsigned int back;

    cin >> people >> front >> back;

    cout << min(people - front, back + 1) << '\n';

    return 0;
}
