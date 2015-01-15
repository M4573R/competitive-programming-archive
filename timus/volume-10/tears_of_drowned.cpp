#include <algorithm>
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

    unsigned int skins;
    cin >> skins;

    unsigned int total_sheets {0};
    unsigned int max_sheets   {0};

    for (unsigned int i {0}; i < skins; ++i)
    {
        unsigned int sheets;
        cin >> sheets;

        total_sheets += sheets;
        max_sheets    = max(max_sheets, sheets);
    }

    cout << total_sheets + max_sheets << '\n';

    return 0;
}
