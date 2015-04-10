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

    unsigned int time;
    cin >> time;

    unsigned int hours   {time / 60 / 60};
    unsigned int minutes {time / 60 % 60};
    unsigned int seconds {time % 60};

    cout << hours << ':' << minutes << ':' << seconds << '\n';

    return 0;
}
