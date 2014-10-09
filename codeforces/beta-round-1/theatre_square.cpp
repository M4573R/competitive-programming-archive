#include <cmath>
#include <iostream>

using namespace std;

inline void use_io_iptimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_iptimizations();

    unsigned int theatre_square_width;
    unsigned int theatre_square_height;
    unsigned int flagstone_size;

    cin >> theatre_square_width >> theatre_square_height >> flagstone_size;

    cout << static_cast<long long>(
                (ceil(theatre_square_width  /
                      static_cast<double>(flagstone_size)) *
                 ceil(theatre_square_height /
                      static_cast<double>(flagstone_size)))
            );

    return 0;
}
