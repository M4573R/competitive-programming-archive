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

    unsigned int a_balls;
    unsigned int b_balls;

    cin >> a_balls >> b_balls;

    unsigned int a_upper_limit;
    unsigned int b_upper_limit;

    cin >> a_upper_limit >> b_upper_limit;

    cout << (a_balls > b_balls ? "First" : "Second") << '\n';

    return 0;
}
