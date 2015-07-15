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

    unsigned int length;
    unsigned int piece_a;
    unsigned int piece_b;
    unsigned int piece_c;

    cin >> length >> piece_a >> piece_b >> piece_c;

    unsigned int pieces {0};

    for (unsigned int i {0}; i <= length; ++i)
    {
        for (unsigned int j {0}; j <= length - i; ++j)
        {
            unsigned int k {length - i - j};

            if (i % piece_a == 0 && j % piece_b == 0 && k % piece_c == 0)
            {
                pieces = max(pieces, i / piece_a + j / piece_b + k / piece_c);
            }
        }
    }

    cout << pieces << '\n';

    return 0;
}
