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

    unsigned int students;
    cin >> students;

    vector<unsigned int> ratings(students);

    for (auto& rating : ratings)
    {
        cin >> rating;
    }

    for (unsigned int i {0}; i < students; ++i)
    {
        unsigned int position {1};

        for (auto rating : ratings)
        {
            if (rating > ratings[i])
            {
                ++position;
            }
        }

        cout << position << (i + 1 < students ? ' ' : '\n');
    }

    return 0;
}
