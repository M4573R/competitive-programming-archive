#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int first;
        unsigned int second;

        cin >> first >> second;

        cout << "Case " << test << ": " << first + second << '\n';
    }

    return 0;
}
