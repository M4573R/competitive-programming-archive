#include <algorithm>
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

    vector<unsigned int> lengths(6);

    for (auto& length : lengths)
    {
        cin >> length;
    }

    sort(lengths.begin(), lengths.end());

    if (lengths[0] == lengths[3])
    {
        cout << (lengths[4] == lengths[5] ? "Elephant" : "Bear");
    }
    else if (lengths[1] == lengths[4])
    {
        cout << "Bear";
    }
    else if (lengths[2] == lengths[5])
    {
        cout << (lengths[0] == lengths[1] ? "Elephant" : "Bear");
    }
    else
    {
        cout << "Alien";
    }

    cout << '\n';

    return 0;
}
