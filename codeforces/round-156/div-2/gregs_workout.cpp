#include <algorithm>
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

    unsigned int exercises;
    cin >> exercises;

    vector<unsigned int> repetitions(3);

    for (unsigned int i {0}; i < exercises; ++i)
    {
        unsigned int times;
        cin >> times;

        repetitions[i % 3] += times;
    }

    unsigned int max_repetitions {
        *max_element(repetitions.cbegin(), repetitions.cend())
    };

    cout << (repetitions[0] == max_repetitions ? "chest"  :
             repetitions[1] == max_repetitions ? "biceps" :
                                                 "back")
         << '\n';

    return 0;
}
