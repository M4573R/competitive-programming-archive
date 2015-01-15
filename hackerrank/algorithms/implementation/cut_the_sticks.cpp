#include <iostream>
#include <map>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int sticks;
    cin >> sticks;

    map<unsigned int, unsigned int> count_by_length;

    for (unsigned int i {0}; i < sticks; ++i)
    {
        unsigned int length;
        cin >> length;

        ++count_by_length[length];
    }

    for (auto& length_and_count : count_by_length)
    {
        cout << sticks << '\n';
        sticks -= length_and_count.second;
    }

    return 0;
}
