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
        unsigned int towns;
        cin >> towns;

        unsigned int total_routes {1};

        for (unsigned int i {0}; i < towns - 1; ++i)
        {
            unsigned int routes;
            cin >> routes;

            total_routes = (total_routes * routes) % 1234567;
        }

        cout << total_routes << '\n';
    }

    return 0;
}
