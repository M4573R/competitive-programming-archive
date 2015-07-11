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

    unsigned int students;
    unsigned int future_participations;

    cin >> students >> future_participations;

    unsigned int eligible {0};

    for (unsigned int i {0}; i < students; ++i)
    {
        unsigned int participations;
        cin >> participations;

        if (participations + future_participations <= 5)
        {
            ++eligible;
        }
    }

    cout << eligible / 3 << '\n';

    return 0;
}
