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

    unsigned int participants;
    unsigned int kth_finisher;

    cin >> participants >> kth_finisher;

    vector<unsigned int> scores(participants);

    for (unsigned int i {0}; i < participants; ++i)
    {
        cin >> scores[i];
    }

    unsigned int i = kth_finisher - 1;

    if (scores[i] == 0)
    {
        while (i > 0 && scores[i] == scores[i - 1])
        {
            --i;
        }
    }
    else
    {
        while (i < participants && scores[i] == scores[kth_finisher - 1])
        {
            ++i;
        }
    }

    cout << i << '\n';

    return 0;
}
