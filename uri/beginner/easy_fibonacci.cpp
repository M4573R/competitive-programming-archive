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

    unsigned int count;
    cin >> count;

    unsigned int current {0};
    unsigned int next    {1};

    for (unsigned int i {0}; i < count; ++i)
    {
        cout << current << (i < count - 1 ? ' ' : '\n');

        current += next;
        swap(current, next);
    }

    return 0;
}
