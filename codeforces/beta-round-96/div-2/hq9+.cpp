#include <iostream>
#include <set>
#include <string>

using namespace std;

const set<char> output_instructions {'H', 'Q', '9'};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string program;
    cin >> program;

    for (auto instruction : program)
    {
        if (output_instructions.find(instruction) != output_instructions.end())
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
