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

    unsigned int users;
    unsigned int increase;
    unsigned int day;

    cin >> users >> increase >> day;

    for (unsigned int i {0}; i < day; ++i)
    {
        users *= increase;
    }

    cout << users << '\n';

    return 0;
}
