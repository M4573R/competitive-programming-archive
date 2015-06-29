#include <iostream>
#include <vector>

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

    unsigned int participants;
    unsigned int kth_finisher;

    cin >> participants >> kth_finisher;

    vector<unsigned int> scores(participants);

    for (auto& score : scores)
    {
        cin >> score;
    }

    unsigned int advanced {0};

    for (auto score : scores)
    {
        if (score > 0 && score >= scores[kth_finisher - 1])
        {
            ++advanced;
        }
    }

    cout << advanced << '\n';

    return 0;
}
