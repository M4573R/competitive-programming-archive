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

    unsigned long long width;
    unsigned long long height;

    cin >> width >> height;

    unsigned long long ships {0};

    while (height)
    {
        ships += width / height;
        width %= height;

        swap(width, height);
    }

    cout << ships << '\n';

    return 0;
}
