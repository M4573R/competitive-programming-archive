#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int initial_a;
    unsigned int initial_b;

    cin >> initial_a >> initial_b;

    unsigned int all_in_a;
    unsigned int empty_b;

    cin >> all_in_a >> empty_b;

    unsigned int empty_a;
    unsigned int all_in_b;

    cin >> empty_a >> all_in_b;

    cout << initial_a - empty_a << ' ' << initial_b - empty_b << '\n';

    return 0;
}
