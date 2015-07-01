#include <cmath>
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

    for (unsigned int width; cin >> width && width > 0; )
    {
        unsigned int height;
        unsigned int percentage;

        cin >> height >> percentage;

        double area {width * height * 100.0 / percentage};

        cout << static_cast<unsigned int>(sqrt(area)) << '\n';
    }

    return 0;
}
