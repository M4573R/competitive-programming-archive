#include <cstdlib>
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

    unsigned int size;
    cin >> size;

    int main_sum      {0};
    int secondary_sum {0};

    for (unsigned int i {0}; i < size; ++i)
    {
        for (unsigned int j {0}; j < size; ++j)
        {
            int element;
            cin >> element;

            if (i == j)
            {
                main_sum += element;
            }

            if (i + j == size - 1)
            {
                secondary_sum += element;
            }
        }
    }

    cout << abs(main_sum - secondary_sum) << '\n';

    return 0;
}
