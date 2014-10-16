#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

enum Piece
{
    a = 1, b = 2, c = 3
};

int main()
{
    use_io_optimizations();

    unsigned int pieces_count;
    cin >> pieces_count;

    unsigned int as_count {0};
    unsigned int bs_count {0};
    unsigned int cs_count {0};

    for (unsigned int i {0}; i < pieces_count; ++i)
    {
        unsigned int piece;
        cin >> piece;

        switch (piece)
        {
        case a:
            ++as_count;
            break;

        case b:
            ++bs_count;
            break;

        case c:
            ++cs_count;
            break;
        }
    }

    long long upper_bound = (pieces_count > 5 ?
                                static_cast<long long>(pieces_count) - 1 :
                                static_cast<long long>(pieces_count) - 2);

    if (as_count > upper_bound ||
        bs_count > upper_bound ||
        cs_count > upper_bound)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }

    return 0;
}
