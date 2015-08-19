#include <iostream>
#include <utility>

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

    unsigned int presses;
    cin >> presses;

    unsigned int a_count {1};
    unsigned int b_count {0};

    for (unsigned int i {0}; i < presses; ++i)
    {
        a_count += b_count;
        swap(a_count, b_count);
    }

    cout << a_count << ' ' << b_count << '\n';

    return 0;
}
