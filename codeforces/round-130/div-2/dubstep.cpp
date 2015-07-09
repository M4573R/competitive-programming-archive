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

    string song;
    cin >> song;

    string::size_type current {0};
    string::size_type next    {min(song.find("WUB", current), song.size())};

    while (current < song.size())
    {
        if (current != next)
        {
            cout << song.substr(current, next - current) << ' ';
        }

        current = next + 3;
        next    = min(song.find("WUB", current), song.size());
    }

    cout << '\n';

    return 0;
}
