#include <iostream>
#include <string>

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

    string first;
    string second;

    cin >> first >> second;

    ++first.back();

    for (string::size_type i {first.size() - 1}; i > 0 && first[i] > 'z'; --i)
    {
        first[i] = 'a';
        ++first[i - 1];
    }

    cout << (first == second ? "No such string" : first) << '\n';

    return 0;
}
