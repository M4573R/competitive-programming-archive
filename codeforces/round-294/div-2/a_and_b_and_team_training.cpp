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

    unsigned int experienced;
    unsigned int newbies;

    cin >> experienced >> newbies;

    cout << min({(experienced + newbies) / 3, experienced, newbies}) << '\n';

    return 0;
}
