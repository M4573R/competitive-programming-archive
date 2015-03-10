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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int flows;
        cin >> flows;

        unsigned int max_flow {0};

        for (unsigned int i {0}; i < flows; ++i)
        {
            unsigned int flow;
            cin >> flow;

            max_flow = max(max_flow, flow);
        }

        cout << max_flow << '\n';
    }

    return 0;
}
