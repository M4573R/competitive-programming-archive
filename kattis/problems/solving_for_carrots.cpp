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

    unsigned int contestants;
    unsigned int solved_huffle_puff;

    cin >> contestants >> solved_huffle_puff;

    cout << solved_huffle_puff << '\n';

    return 0;
}
