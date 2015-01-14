#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int statements_count;
    cin >> statements_count;

    int x {0};

    for (unsigned int i {0}; i < statements_count; ++i)
    {
        string statement;
        cin >> statement;

        statement.find('+') != string::npos ? ++x : --x;
    }

    cout << x << '\n';

    return 0;
}
