#include <algorithm>
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

    long long books;
    cin >> books;

    long long digits {0};

    for (long long i {1}, j {1}; i <= 10; ++i, j *= 10)
    {
        digits += max(0ll, min(books, j * 10 - 1) - j + 1) * i;
    }

    cout << digits << '\n';

    return 0;
}
