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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        char delimiter;

        unsigned int hour;
        unsigned int minutes;

        cin >> hour >> delimiter >> minutes;

        cout << (minutes % 10 == 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}
