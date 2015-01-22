#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int size;
    cin >> size;

    vector<unsigned int> elements(size);

    for (auto& element : elements)
    {
        cin >> element;
    }

    sort(elements.begin(), elements.end());

    for (auto element : elements)
    {
        cout << element << '\n';
    }

    return 0;
}
