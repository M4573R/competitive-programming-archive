#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int play_number;
        cin >> play_number;

        cout << (play_number % 2 == 0 ? "ALICE" : "BOB") << '\n';
    }

    return 0;
}
