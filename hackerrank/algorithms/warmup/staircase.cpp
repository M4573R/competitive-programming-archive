#include <iomanip>
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

    unsigned int height;
    cin >> height;

    for (unsigned int i {1}; i <= height; ++i)
    {
        cout << setw(height) << string(i, '#') << '\n';
    }

    return 0;
}
