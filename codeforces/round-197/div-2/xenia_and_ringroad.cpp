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

    unsigned int houses;
    unsigned int tasks;

    cin >> houses >> tasks;

    unsigned int current    {1};
    unsigned long long time {0};

    for (unsigned int i {0}; i < tasks; ++i)
    {
        unsigned int next;
        cin >> next;

        if (current <= next)
        {
            time += next - current;
        }
        else
        {
            time += houses - current + next;
        }

        current = next;
    }

    cout << time << '\n';

    return 0;
}
