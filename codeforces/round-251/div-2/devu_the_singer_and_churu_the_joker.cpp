#include <iostream>

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

    unsigned int songs;
    unsigned int event_duration;

    cin >> songs >> event_duration;

    unsigned int songs_duration {0};

    for (unsigned int i {0}; i < songs; ++i)
    {
        unsigned int duration;
        cin >> duration;

        songs_duration += duration;
    }

    if (songs_duration + 10 * (songs - 1) > event_duration)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << (event_duration - songs_duration) / 5 << '\n';
    }

    return 0;
}
