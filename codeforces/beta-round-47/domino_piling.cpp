#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

constexpr unsigned int domino_width  {1};
constexpr unsigned int domino_height {2};

int main()
{
    use_io_optimizations();

    unsigned int board_width;
    unsigned int board_height;

    cin >> board_width >> board_height;

    unsigned int vertical_dominoes {
        (board_width / domino_width) * (board_height / domino_height)
    };

    unsigned int horizontail_dominoes {
        board_height % 2 != 0 ? board_width / domino_height : 0
    };

    cout << vertical_dominoes + horizontail_dominoes << '\n';

    return 0;
}
