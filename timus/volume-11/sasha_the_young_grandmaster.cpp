#include <cmath>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
int king_hits(int x, int y, int n)
{
    return ((x > 1) +
            (y > 1) +
            (x < n) +
            (y < n) +
            (x > 1 && y > 1) +
            (x > 1 && y < n) +
            (x < n && y > 1) +
            (x < n && y < n));
}

inline
int knight_hits(int x, int y, int n)
{
    return ((x - 2 >= 1 && y - 1 >= 1) +
            (x - 2 >= 1 && y + 1 <= n) +
            (x + 2 <= n && y - 1 >= 1) +
            (x + 2 <= n && y + 1 <= n) +
            (x - 1 >= 1 && y - 2 >= 1) +
            (x - 1 >= 1 && y + 2 <= n) +
            (x + 1 <= n && y - 2 >= 1) +
            (x + 1 <= n && y + 2 <= n));
}

inline
int bishop_hits(int x, int y, int n)
{
    return 2 * (n - 1) - abs(x - y) - abs(n + 1 - (x + y));
}

inline
int rook_hits(int x, int y, int n)
{
    return 2 * n - 2;
}

inline
int queen_hits(int x, int y, int n)
{
    return bishop_hits(x, y, n) + rook_hits(x, y, n);
}

int main()
{
    use_io_optimizations();

    int field_size;
    cin >> field_size;

    int x;
    int y;

    cin >> x >> y;

    cout << "King: "   << king_hits  (x, y, field_size) << '\n'
         << "Knight: " << knight_hits(x, y, field_size) << '\n'
         << "Bishop: " << bishop_hits(x, y, field_size) << '\n'
         << "Rook: "   << rook_hits  (x, y, field_size) << '\n'
         << "Queen: "  << queen_hits (x, y, field_size) << '\n';

    return 0;
}
