#include <algorithm>
#include <cctype>
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

    string first;
    string second;

    cin >> first >> second;

    transform(first.begin(),
              first.end(),
              first.begin(),
              [](unsigned char letter) { return tolower(letter); });

    transform(second.begin(),
              second.end(),
              second.begin(),
              [](unsigned char letter) { return tolower(letter); });

    int comparison {first.compare(second)};

    if (comparison < 0)
    {
        cout << -1;
    }
    else if (comparison > 0)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    cout << '\n';

    return 0;
}
