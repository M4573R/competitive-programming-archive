#include <cstdlib>
#include <iostream>
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

    string first;
    string second;

    cin >> first >> second;

    vector<int> frequencies(26);

    for (auto letter : first)
    {
        ++frequencies[letter - 'a'];
    }

    for (auto letter : second)
    {
        --frequencies[letter - 'a'];
    }

    unsigned int deletions {0};

    for (auto frequency : frequencies)
    {
        deletions += abs(frequency);
    }

    cout << deletions << '\n';

    return 0;
}
