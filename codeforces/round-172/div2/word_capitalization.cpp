#include <cctype>
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

    string word;
    cin >> word;

    if (islower(word.front()))
    {
        word.front() = toupper(word.front());
    }

    cout << word << '\n';

    return 0;
}
