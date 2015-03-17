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

    unsigned int test {1};

    unsigned int devices;
    unsigned int operations;
    unsigned int capacity;

    while (cin >> devices >> operations >> capacity &&
           !(devices == 0 && operations == 0 && capacity == 0))
    {
        vector<unsigned int> consumptions(devices);

        for (auto& consumption : consumptions)
        {
            cin >> consumption;
        }

        vector<bool> is_on(devices);

        unsigned int current_consumption {0};
        unsigned int max_consumption     {0};

        for (unsigned int i {0}; i < operations; ++i)
        {
            unsigned int device;
            cin >> device;

            if (is_on[device - 1])
            {
                current_consumption -= consumptions[device - 1];
            }
            else
            {
                current_consumption += consumptions[device - 1];
            }

            max_consumption    = max(max_consumption, current_consumption);
            is_on[device - 1]  = !is_on[device - 1];
        }

        cout << "Sequence " << test++ << '\n';

        if (max_consumption > capacity)
        {
            cout << "Fuse was blown.\n";
        }
        else
        {
            cout << "Fuse was not blown.\n"
                 << "Maximal power consumption was "
                 << max_consumption
                 << " amperes.\n";
        }

        cout << '\n';
    }

    return 0;
}
