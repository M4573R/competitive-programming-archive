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

    unsigned int events;
    cin >> events;

    unsigned int officers         {0};
    unsigned int untreated_crimes {0};

    for (unsigned int i {0}; i < events; ++i)
    {
        int event;
        cin >> event;

        if (event < 0)
        {
            if (officers > 0)
            {
                --officers;
            }
            else
            {
                ++untreated_crimes;
            }
        }
        else
        {
            officers += event;
        }
    }

    cout << untreated_crimes << '\n';

    return 0;
}
