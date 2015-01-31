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

    unsigned int routes;
    cin >> routes;

    for (unsigned int route {1}; route <= routes; ++route)
    {
        unsigned int stops;
        cin >> stops;

        unsigned int max_from {0};
        unsigned int max_to   {0};

        int max_niceness     {-1};
        int current_niceness {0};

        for (unsigned int from {1}, to {2}; to <= stops; ++to)
        {
            int niceness;
            cin >> niceness;

            current_niceness += niceness;

            if ((max_niceness  < current_niceness) ||
                (max_niceness == current_niceness && max_from == from))
            {
                max_from     = from;
                max_to       = to;
                max_niceness = current_niceness;
            }

            if (current_niceness < 0)
            {
                from             = to;
                current_niceness = 0;
            }
        }

        if (max_niceness >= 0)
        {
            cout << "The nicest part of route " << route
                 << " is between stops "
                 << max_from << " and " << max_to;
        }
        else
        {
            cout << "Route " << route << " has no nice parts";
        }

        cout << '\n';
    }

    return 0;
}
