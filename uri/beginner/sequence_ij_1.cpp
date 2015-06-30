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

    for (unsigned int i {1}, j {60}; i <= 37; i += 3, j -= 5)
    {
        cout << "I=" << i << " J=" << j << '\n';
    }

    return 0;
}
