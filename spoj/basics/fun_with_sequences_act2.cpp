#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_sequence(vector<int>& sequence)
{
    unsigned int lenght;
    cin >> lenght;

    sequence.resize(lenght);

    for (auto& element : sequence)
    {
        cin >> element;
    }
}

int main()
{
    use_io_optimizations();

    vector<int> first;
    read_sequence(first);

    vector<int> second;
    read_sequence(second);

    vector<int> intersection;

    set_intersection(first.cbegin(),  first.cend(),
                     second.cbegin(), second.cend(),
                     back_inserter(intersection));

    for (auto i = intersection.cbegin(); i != intersection.cend(); ++i)
    {
        cout << *i << " \n"[i + 1 == intersection.cend()];
    }

    return 0;
}
