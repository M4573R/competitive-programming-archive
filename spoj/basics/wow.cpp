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

    unsigned int o_count;
    cin >> o_count;

    cout << 'W' << string(o_count, 'o') << "w\n";

    return 0;
}
