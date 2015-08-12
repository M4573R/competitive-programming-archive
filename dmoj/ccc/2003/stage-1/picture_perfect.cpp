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

    for (unsigned int photos; cin >> photos && photos != 0; )
    {
        unsigned int width  {1};
        unsigned int height {photos};

        for (unsigned int i {1}; i * i <= photos; ++i)
        {
            if (photos % i == 0)
            {
                width  = i;
                height = photos / i;
            }
        }

        cout << "Minimum perimeter is " << 2 * (width + height)
             << " with dimensions "     << width << " x " << height
             << '\n';
    }

    return 0;
}
