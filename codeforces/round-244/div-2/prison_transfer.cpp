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

    unsigned int prisoners;
    unsigned int max_severity;
    unsigned int for_transfer;

    cin >> prisoners >> max_severity >> for_transfer;

    unsigned int ways    {0};
    unsigned int segment {0};

    for (unsigned int i {0}; i < prisoners; ++i)
    {
        unsigned int severity;
        cin >> severity;

        if (severity <= max_severity)
        {
            ++segment;

            if (segment >= for_transfer)
            {
                ++ways;
            }
        }
        else
        {
            segment = 0;
        }
    }

    cout << ways << '\n';

    return 0;
}
