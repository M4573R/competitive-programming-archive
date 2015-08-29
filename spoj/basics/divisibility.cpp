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
        unsigned int upper_limit;
        unsigned int first;
        unsigned int second;

        cin >> upper_limit >> first >> second;

        for (unsigned int i {2}; i < upper_limit; ++i)
        {
            if (i % first == 0 && i % second != 0)
            {
                cout << i << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
