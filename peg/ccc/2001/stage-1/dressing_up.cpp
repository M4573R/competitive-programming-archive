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

    int height;
    cin >> height;

    for (int i {1}; i <= height; i += 2)
    {
        string line {string(i, '*') +
                     string(2 * (height - i), ' ') +
                     string(i, '*')};

        cout << line << '\n';
    }

    for (int i {height - 2}; i >= 1; i -= 2)
    {
        string line {string(i, '*') +
                     string(2 * (height - i), ' ') +
                     string(i, '*')};

        cout << line << '\n';
    }

    return 0;
}
