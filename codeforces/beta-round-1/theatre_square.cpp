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

    unsigned long long theatre_square_width;
    unsigned long long theatre_square_height;
    unsigned long long flagstone_size;

    cin >> theatre_square_width >> theatre_square_height >> flagstone_size;

    unsigned long long horizontal {
        (theatre_square_width + flagstone_size - 1) / flagstone_size
    };

    unsigned long long vertical {
        (theatre_square_height + flagstone_size - 1) / flagstone_size
    };

    cout << horizontal * vertical << '\n';

    return 0;
}
