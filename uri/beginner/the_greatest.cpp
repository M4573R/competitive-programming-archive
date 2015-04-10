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

    int first;
    int second;
    int third;

    cin >> first >> second >> third;

    cout << max(first, max(second, third)) << " eh o maior\n";

    return 0;
}
