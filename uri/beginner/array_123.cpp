#include <iostream>
#include <string>
#include <vector>

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

    for (unsigned int size; cin >> size; )
    {
        vector<string> lines(size, string(size, '3'));

        for (unsigned int i {0}; i < size; ++i)
        {
            lines[i][i]            = '1';
            lines[i][size - 1 - i] = '2';
        }

        for (const auto& line : lines)
        {
            cout << line << '\n';
        }
    }

    return 0;
}
