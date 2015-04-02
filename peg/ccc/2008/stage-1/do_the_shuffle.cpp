#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
void press(string& playlist, unsigned int button)
{
    switch (button)
    {
    case 1:
        playlist = playlist.substr(1) + playlist.front();
        break;

    case 2:
        playlist = playlist.back() + playlist.substr(0, playlist.size() - 1);
        break;

    case 3:
        swap(playlist[0], playlist[1]);
        break;

    case 4:
        for (auto song = playlist.cbegin(); song != playlist.cend(); ++song)
        {
            cout << *song << (song + 1 != playlist.cend() ? ' ' : '\n');
        }

        break;
    }
}

int main()
{
    use_io_optimizations();

    string playlist {"ABCDE"};

    for (unsigned int button, times; cin >> button >> times; )
    {
        for (unsigned int i {0}; i < times; ++i)
        {
            press(playlist, button);
        }

        if (button == 4 && times == 1)
        {
            break;
        }
    }

    return 0;
}
