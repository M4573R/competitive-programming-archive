#include <iostream>
#include <string>
#include <utility>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

string canonical(const string& sequence)
{
    if (sequence.size() % 2)
    {
        return sequence;
    }

    auto half = sequence.size() / 2;

    string first  {canonical(sequence.substr(0, half))};
    string second {canonical(sequence.substr(half, half))};

    if (first > second)
    {
        swap(first, second);
    }

    return first + second;
}

int main()
{
    use_io_optimizations();

    string first;
    string second;

    cin >> first >> second;

    cout << (canonical(first) == canonical(second) ? "YES" : "NO") << '\n';

    return 0;
}
