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

    unsigned int previous;
    unsigned int current;

    cin >> previous >> current;

    unsigned int length {2};

    while (previous >= current)
    {
        unsigned int next {previous - current};

        previous = current;
        current  = next;

        ++length;
    }

    cout << length << '\n';

    return 0;
}
